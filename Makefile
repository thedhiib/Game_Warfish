einstall:
	cd C:/Users/programm/Warfish && git -C emsdk pull || git clone https://github.com/emscripten-core/emsdk 
	cd C:/Users/programm/Warfish/emsdk && \
		./emsdk install 3.1.24 && \
		./emsdk activate 3.1.24 && \
		npm i http-server -g
erun:
	cd C:/Users/programm/Warfish/emsdk && \
		./emsdk install 3.1.24 && \
		./emsdk activate 3.1.24 && \
		./emsdk_env.bat && \
		emcc ../warfish.c -s WASM=1 -o warfish.html && \
	cd C:/Users/programm/Warfish && \
		http-server