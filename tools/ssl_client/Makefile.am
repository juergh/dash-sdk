

SUBDIRS = .


INCLUDES = -Iinclude -Wall


LIBS = -lssl -lpthread

bin_PROGRAMS = ssl_client

ssl_client_SOURCES =				\
			src/main.cpp 		\
			src/transport.cpp 	\
			src/server.cpp 		\
        		src/client.cpp 		\
        		src/sslclient.cpp

EXTRA_DIST = 	src/*.h					\
		windows/ssl_client/ssl_client.sln 	\
		windows/ssl_client/ssl_client.vcproj	
