cleos wallet unlock -n debug --password PW5JGqrHwsAphXLGcZ4rHAJqQxmGQXdL42puB5Vjo14odGspwYFvo

EOS_BUILD_PATH=$HOME/eos/build
EOS_KEY=EOS8k4wDWyrq9yPUL17YKqThf5F5VVMs5c8diRZQfGKG9698dd6na

cleos create account eosio test.user ${EOS_KEY} ${EOS_KEY}
cleos set contract test.user ../eosio.keccak -p test.user

cleos push action test.user testsha3 '["f5be9644ac36b93af5295229a59e942f0c30272961ef92c0720914d3f9884c95"]' -p test.user
