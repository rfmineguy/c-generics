docker run --rm -it -v $(pwd):$(pwd) -w $(pwd) alpine sh -c "gcc main.c redblacktree_wip.c -o main_x86"
docker run --rm -it -e DISPLAY=192.168.1.142:0 -v $(pwd):$(pwd) -w $(pwd) alpine gf2 ./main_x86
