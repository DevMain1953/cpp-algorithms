project:
	gcc -std=c99 -Wall -Wpedantic life-expectancy.c
	./a.exe
installemsdk: 
	cd .. && git clone https://github.com/emscripten-core/emsdk.git
	cd ../emsdk && emsdk install latest && emsdk activate latest && emsdk_env.bat && emcc life-expectancy.c -s NO_EXIT_RUNTIME=0 -o output.html
	npm i http-server -g
runserver:
	cd ../emsdk && http-server