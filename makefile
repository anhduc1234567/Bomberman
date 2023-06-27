all:

	g++ -I"C:\SFML-2.5.1\include" -L"C:\SFML-2.5.1\lib" -o map map.cpp -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio 
