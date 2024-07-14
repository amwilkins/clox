#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "vm.h"

int main(int argc, const char *argv[]) {
  initVM();

  Chunk chunk;

  // initializing chunk
  initChunk(&chunk);

  // writing constant to chunk
  int constant = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant, 123);

  // writing constant to chunk
  constant = addConstant(&chunk, 3.4);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant, 123);

  // add
  writeChunk(&chunk, OP_ADD, 123);

  // writing constant to chunk
  constant = addConstant(&chunk, 5.6);
  writeChunk(&chunk, OP_CONSTANT, 123);
  writeChunk(&chunk, constant, 123);

  // divide
  writeChunk(&chunk, OP_DIVIDE, 123);

  // negating the top value
  writeChunk(&chunk, OP_NEGATE, 123);

  writeChunk(&chunk, OP_RETURN, 123);

  // printing chunk
  dissassembleChunk(&chunk, "test chunk");
  interpret(&chunk);
  freeVM();

  // removing chunk from memory
  freeChunk(&chunk);
  return 0;
}
