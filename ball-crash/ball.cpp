#include "ball.h"






ball::~ball()
{
}

const double ball::angle_v()const
{
	if (vx == 0)
	{
		if(vy>0)return PI / 2;
		else if (vy<0)return 3*PI / 2;
		else return 0;
	}
	else
	{
		if (vx > 0 && vy >= 0) return atan(vy / vx);
		else if (vx > 0 && vy < 0)return (2 * PI + atan(vy / vx));
		else if (vx < 0 )return (PI + atan(vy / vx));
	}
}

const double ball::angle_a()const
{
	if (ax == 0)
	{
		if (ay>0)return PI / 2;
		else if(ay<0)return 3 * PI/2;
		else return 0;
	}
	else 
	{
		if (ax > 0 && ay >= 0) return atan(ay / ax);
		else if (ax > 0 && ay < 0)return (2 * PI + atan(ay / ax));
		else if (ax < 0 )return (PI + atan(ay / ax));
	}
}

void ball::move()
{
	int sign;
	p.y = p.y +0.01* vy;
	sign = (vy > 0) ? 1 : ((vy < 0) ? -1 : 0);
	vy = vy + 0.02*ay - (sign*u_ground * 10);
	p.x = p.x + 0.01* vx;
	sign = (vx > 0) ? 1 : ((vx < 0) ? -1 : 0);
	vx = vx + 0.02*ax - (sign*u_ground * 10);
}

void ball::CrashBorder()
{
	if (p.y >= YMAX - r) {
		vy = -vy * 0.8;p.y = YMAX - r - 0.1;
	}
	if (p.y <= r){
		vy = -vy * 0.8;p.y = r + 0.1;
	}
	if (p.x >= XMAX - r) {
		vx = -vx * 0.8;p.x = XMAX - r - 0.1;
	}
	if (p.x <= r) {
		vx = -vx * 0.8;p.x = r + 0.1;
	}
}

const void ball::display()
{
	putimage(p.x - r, p.y - r, &img);
}



void impact(ball & b1, ball & b2)
{
	double x1 = b1.p.x + 0.01*b1.vx;
	double y1 = b1.p.y + 0.01*b1.vy;
	double x2 = b2.p.x + 0.01*b2.vx;
	double y2 = b2.p.y + 0.01*b2.vy;
	if (((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)) <= 4*r*r)
	{
		double dx = (b2.p.x - b1.p.x);
		double dy = (b2.p.y - b1.p.y);
		double angle;
		if (dx == 0)
		{
			if (dy>0) angle= PI / 2;
			else if (dy<0)angle = 3 * PI / 2;
			else angle = 0;
		}
		else
		{
			if (dx > 0 && dy >= 0) angle = atan(dy / dx);
			else if (dx > 0 && dy < 0)angle = (2 * PI + atan(dy / dx));
			else if (dx < 0 ) angle = (PI + atan(dy / dx));
		}
		double vx1 = b1.vx*cos(angle) + b1.vy*cos(angle - PI / 2);
		double vy1 = b1.vx*cos(angle + PI / 2) + b1.vy*cos(angle);
		double vx2 = b2.vx*cos(angle) + b2.vy*cos(angle - PI / 2);
		double vy2 = b2.vx*cos(angle + PI / 2) + b2.vy*cos(angle);
		double m1 = b1.m, m2 = b1.m;
		double t = 0.8*((m1 - m2)*vx1 + 2 * m2*vx2) / (m1+ m2);
		vx2= 0.8*((m2 -m1)*vx2 + 2 * m1*vx1) / (m1 + m2);
		vx1 = t;
		b1.vx = vx1 * cos(angle) + vy1 * cos(angle + PI / 2);
		b1.vy = vx1 * cos(angle - PI / 2) + vy1 * cos(angle);
		b2.vx = vx2 * cos(angle) + vy2 * cos(angle + PI / 2);
		b2.vy = vx2 * cos(angle - PI / 2) + vy2 * cos(angle);

		if (((b1.p.x - b2.p.x)*(b1.p.x - b2.p.x) + (b1.p.y - b2.p.y)*(b1.p.y - b2.p.y)) <= 4 * r*r) {
			/*b1.vx = -(5 * cos(angle) + 5 * cos(angle - PI / 2));
			b1.vy = -(5 * cos(angle + PI / 2) + 5 * cos(angle));
			b1.vx = 5 * cos(angle) + 5 * cos(angle - PI / 2);
			b1.vy = 5 * cos(angle + PI / 2) + 5 * cos(angle);*/
			/*b1.p.x -= (0.5*cos(angle) + 0.5*cos(angle - PI / 2));
			b1.p.y -= (0.5*cos(angle + PI / 2) + 0.5*cos(angle));
			b2.p.x += (0.5*cos(angle) + 0.5*cos(angle - PI / 2));
			b2.p.y += (0.5*cos(angle + PI / 2) + 0.5*cos(angle));*/
			if (b1.getV() < 1 && b2.getV() < 5) {
				b1.vx = 0;
				b2.vx = 0;
				b1.vy = 0;
				b2.vy = 0;
			}
		}
	}
}
