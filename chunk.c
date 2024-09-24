#include <stdlib.h> // Include the standard library for memory allocation functions

#include "chunk.h" // Include the header file for the Chunk structure and related functions
#include "memory.h" // Include the header file for memory management functions

// Function to initialize a Chunk structure
void initChunk(Chunk* chunk){
    chunk->count = 0; // Initialize the count of bytes in the chunk to 0
    chunk->capacity = 0; // Initialize the capacity of the chunk to 0
    chunk->code = NULL; // Initialize the code pointer to NULL
}

// Function to write a byte to the Chunk structure
void writeChunk(Chunk* chunk, uint8_t byte){
    // Check if the current capacity is less than the required capacity
    if(chunk->capacity < chunk->count + 1){
        int oldCapacity = chunk->capacity; // Store the old capacity
        chunk->capacity = GROW_CAPACITY(oldCapacity); // Grow the capacity using a macro
        // Reallocate memory for the code array with the new capacity
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
    }

    chunk->code[chunk->count] = byte; // Write the byte to the code array
    chunk->count++; // Increment the count of bytes in the chunk
}