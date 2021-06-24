build_dir := build
CFLAGS=-g
LFLAGS=-lm
clean:
	@rm -rf build/*

%:|$(build_dir)
	@gcc $(CFLAGS) -o build/$@ $@.c $(LFLAGS)
	-build/$@

$(build_dir):
	@mkdir $(build_dir)
