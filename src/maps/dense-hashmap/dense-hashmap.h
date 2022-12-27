#include <cstddef>
#include <functional>
#include <utility>

template <typename Key, typename Value, typename Hash = std::hash<Key>>
class DenseHashMap {
public:
    // Constructs a dense hash map with the specified capacity and hash function
    explicit DenseHashMap(std::size_t capacity = 8, Hash hash = Hash())
        : m_capacity(capacity)
        , m_size(0)
        , m_hash(hash)
        , m_keys(new Key[capacity])
        , m_values(new Value[capacity]) 
    {
        // Initialize all keys to the default value
        for (std::size_t i = 0; i < m_capacity; ++i)
            m_keys[i] = Key();
    }

    // Destructor
    ~DenseHashMap() {
        delete[] m_keys;
        delete[] m_values;
    }

    // Inserts a key-value pair into the hash map
    void insert(Key key, Value value) {
        // If the load factor exceeds 0.75, resize the hash map
        if (m_size >= m_capacity * 0.75)
            resize(m_capacity * 2);

        // Calculate the hash of the key
        const std::size_t hash = m_hash(key);

        // Find the first empty slot or the slot with the same key
        std::size_t index = hash % m_capacity;
        while (m_keys[index] != Key() && m_keys[index] != key)
            index = (index + 1) % m_capacity;

        // If the slot is empty, insert the key-value pair and increase the size
        if (m_keys[index] == Key()) {
            m_keys[index] = std::move(key);
            m_values[index] = std::move(value);
            ++m_size;
        }
        // Otherwise, update the value of the existing key
        else {
            m_values[index] = std::move(value);
        }
    }

    // Finds the value associated with the specified key
    Value* find(Key key) {
        // Calculate the hash of the key
        const std::size_t hash = m_hash(key);

        // Find the first empty slot or the slot with the same key
        std::size_t index = hash % m_capacity;
        while (m_keys[index] != Key() && m_keys[index] != key)
            index = (index + 1) % m_capacity;

        // Return a pointer to the value if the key was found, or a null pointer otherwise
        return m_keys[index] == key ? &m_values[index] : nullptr;
    }

private:
    std::size_t m_capacity;       // The capacity of the hash map (number of slots)
    std::size_t m_size;           // The number of key-value pairs in the hash map
    Hash m_hash;                  // The hash function
    Key* m_keys;                  // 
    Value* m_values;              // The values

    // Resizes the hash map to the specified capacity
    void resize(std::size_t new_capacity) {
        // Allocate new arrays for the keys and values
        Key* new_keys = new Key[new_capacity];
        Value* new_values = new Value[new_capacity];

        // Initialize all keys in the new arrays to the default value
        for (std::size_t i = 0; i < new_capacity; ++i)
            new_keys[i] = Key();

        // Rehash all the keys and values into the new arrays
        for (std::size_t i = 0; i < m_capacity; ++i) {
            if (m_keys[i] != Key()) {
                // Calculate the hash of the key
                const std::size_t hash = m_hash(m_keys[i]);

                // Find the first empty slot in the new arrays
                std::size_t index = hash % new_capacity;
                while (new_keys[index] != Key())
                    index = (index + 1) % new_capacity;

                // Insert the key-value pair into the new arrays
                new_keys[index] = std::move(m_keys[i]);
                new_values[index] = std::move(m_values[i]);
            }
        }

        // Deallocate the old arrays and update the capacity and keys/values pointers
        delete[] m_keys;
        delete[] m_values;
        m_capacity = new_capacity;
        m_keys = new_keys;
        m_values = new_values;
    }
};
