//#include <threads>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

//using namespace std;

int main()
{
	
	ALLEGRO_DISPLAY *display;
	
	if(!al_init())
	{
		al_show_native_message_box(NULL,NULL,NULL, "Could no initialize aalegro",NULL,NULL);
		//cout<<"could no initialize aalegro"<<endl;
	}
	display=al_create_display(800,600);
	
	if(!display)
	{
		al_show_native_message_box(NULL,NULL,NULL, "could not create allegro window" , NULL,NULL);
		//cout<<"could not create allegro wondow"<<endl;
	}	

	al_destroy_display(display);
    return 0;

}
