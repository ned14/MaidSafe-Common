/* Copyright (c) 2011 maidsafe.net limited
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice,
    this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.
    * Neither the name of the maidsafe.net limited nor the names of its
    contributors may be used to endorse or promote products derived from this
    software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <memory>
#include "maidsafe/common/tests/chunk_store_api_test.h"
#include "maidsafe/common/hashable_chunk_validation.h"
#include "maidsafe/common/memory_chunk_store.h"

namespace maidsafe {

namespace test {

template <> template <class ValidationType, class VersionType>
void ChunkStoreTest<MemoryChunkStore>::InitChunkStore(
    std::shared_ptr<ChunkStore> *chunk_store,
    bool reference_counting,
    const fs::path&,
    boost::asio::io_service&) {
  chunk_store->reset(new MemoryChunkStore(
      reference_counting,
      std::shared_ptr<ChunkValidation>(
          new HashableChunkValidation<ValidationType, VersionType>)));
}

INSTANTIATE_TYPED_TEST_CASE_P(Memory, ChunkStoreTest, MemoryChunkStore);

}  // namespace test

}  // namespace maidsafe
