#pragma once
#include<easyx.h>
#include<cmath>
#include<cstdio>
#include<string>
#define r 15
#define u_air 0.00
#define u_ground 0.001
#define XMAX 600
#define YMAX 400
#define PI 3.141593


struct point
{
	double x;
	double y;
};
class ball
{
public:
	IMAGE img;
	ball(double m=1, double vx=0, double vy=0, double ax=0, double ay=0,double x = r, double y = r ) : m(m), vx(vx),vy(vy), ax(ax),ay(ay)
	{
		p.x = x;p.y = y;
	}
	~ball();
	const double getX() const { return p.x; }
	const double getY() const { return p.y; }
	const double getV() const { return sqrt(vx*vx + vy * vy); }
	const double angle_v()const;//���ٶȵĽǶ�
	const double angle_a()const;//�ϼ��ٶȵĽǶ�
	void setY(double y) { p.y = y; }
	void setX(double x) { p.x = x; }
	void setaX(double aX) { ax = aX; }
	void setaY(double aY) { ay = aY; }
	void setVX(double VX) { vx = VX; }
	void setVY(double VY) { vy = VY; }
	void move();//�ƶ�
	void CrashBorder();//ײǽ
	const void display();//��ʾ
	friend void impact(ball &b1, ball &b2);//С���໥��ײ
private:
	double m;//����  (kg)
	double vx;//�ٶ���x����ķ��� (0.01*����/ms)
	double vy;//�ٶ���y����ķ��� (0.01*����/ms)

	double ax;//x������ٶ� (0.02*����/ms^2)
	double ay;//y������ٶ� (0.02*����/ms^2)
	point p;//��������(x,y)

};

