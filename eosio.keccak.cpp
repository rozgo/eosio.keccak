#include <eosiolib/eosio.hpp>
#include <eosiolib/crypto.h>

#include "sha3.h"

using namespace eosio;

class keccak : public eosio::contract
{
  public:
    using contract::contract;

    //@abi testsha3
    void testsha3()
    {
      int results = test_sha3();
      printi(results);
    }
};

EOSIO_ABI(keccak, (testsha3))


