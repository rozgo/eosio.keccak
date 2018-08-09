#include <eosiolib/eosio.hpp>
#include <eosiolib/crypto.h>

#include "sha3.h"

using namespace eosio;

template <typename CharT>
static std::string to_hex(const CharT *d, uint32_t s)
{
  std::string r;
  const char *to_hex = "0123456789abcdef";
  uint8_t *c = (uint8_t *)d;
  for (uint32_t i = 0; i < s; ++i)
  {
    (r += to_hex[(c[i] >> 4)]) += to_hex[(c[i] & 0x0f)];
  }
  return r;
}

class keccak : public eosio::contract
{
public:
  using contract::contract;

  //@abi testsha3
  void testsha3(const checksum256 &_msg)
  {
    uint8_t *msg = (uint8_t *)&_msg;
    uint8_t hash[32];
    SHA3_256(hash, msg, 32);
    std::string hash_str = to_hex(hash, 32);
    prints(hash_str.c_str());
  }
};

EOSIO_ABI(keccak, (testsha3))
