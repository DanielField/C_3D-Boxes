all: 
	cd ./ZDK/ && make all && cd ../3D_Boxes/ && make all
clean: 
	cd ./ZDK/ && make clean && cd ../3D_Boxes/ && make clean
rebuild: clean all