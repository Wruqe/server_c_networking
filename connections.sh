#!/bin/bash

## My thought with this is that this will basically send 50 requests in parrallel to the server
## I hope it breaks.
rqs="$1" 
for i in $(seq 1 "$reqs"); do
    curl http://127.0.0.1:3000/ &
done
wait

