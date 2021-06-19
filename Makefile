build_dir := build
clean:
	@rm -rf build/*

%:|$(build_dir)
	@gcc -g -o build/$@ $@.c
	@build/$@

$(build_dir):
	@mkdir $(build_dir)
