#ifndef COSA_H
#define COSA_H



class Cosa
{
    protected:
        int y;
		int x;
    public:
        Cosa(int _y,int _x);
        void setx(int _x){ x=_x;}
        void sety(int _y){ y=_y;}
        int getX() {return x;}
        int getY() {return y;}
		void start(int ,int );
		void paint();
		void del();
		void moverv();
		void moverh();
        
};
#endif
