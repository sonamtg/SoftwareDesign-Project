a.out: Post.o User.o Notification.o State.o display.o update.o app3.o
	g++ -g -Wall Post.o User.o Notification.o State.o display.o update.o app3.o /usr/local/cs/cs251/react.o -lcurl

app3.o: app3.cpp State.h
	g++ -g -Wall -c app3.cpp

app0: Post.o User.o Notification.o State.o display.o update.o app0.o
	g++ -g -Wall Post.o User.o Notification.o State.o app0.o -o app0

app0.o: app0.cpp State.h
	g++ -g -Wall -c app0.cpp

State.o:  Post.h User.h Notification.h State.cpp State.h 
	g++ -g -Wall -c State.cpp

update.o: update.cpp State.h
	g++ -g -Wall -c update.cpp

display.o: display.cpp State.h
	g++ -g -Wall -c display.cpp

Notification.o: Notification.cpp Notification.h
	g++ -g -Wall -c Notification.cpp

User.o: User.cpp User.h
	g++ -g -Wall -c User.cpp

Post.o: Post.cpp Post.h
	g++ -g -Wall -c Post.cpp

clean: 
	rm *.o