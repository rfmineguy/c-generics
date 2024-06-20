echo "Hi"

# docker run --rm -it -v $(pwd):$(shell pwd) -w $(shell pwd) alpine sh -c "gcc main.c redblacktree_wip.c -o out/$(BIN)_x86"
# docker run --rm -it -e DISPLAY=192.168.1.142:0 -v $(shell pwd):$(shell pwd) -w $(shell pwd) alpine gf2 ./out/$(BIN)_x86
