keccak: eosio.keccak.cpp
	eosiocpp -o ../eosio.keccak/eosio.keccak.wast eosio.keccak.cpp
	eosiocpp -g ../eosio.keccak/eosio.keccak.abi eosio.keccak.cpp

clean:
	rm *.wasm *.wast
