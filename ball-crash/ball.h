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
	const double angle_v()const;//合速度的角度
	const double angle_a()const;//合加速度的角度
	void setY(double y) { p.y = y; }
	void setX(double x) { p.x = x; }
	void setaX(double aX) { ax = aX; }
	void setaY(double aY) { ay = aY; }
	void setVX(double VX) { vx = VX; }
	void setVY(double VY) { vy = VY; }
	void move();//移动
	void CrashBorder();//撞墙
	const void display();//显示
	friend void impact(ball &b1, ball &b2);//小球相互碰撞
private:
	double m;//质量  (kg)
	double vx;//速度在x方向的分量 (0.01*像素/ms)
	double vy;//速度在y方向的分量 (0.01*像素/ms)

	double ax;//x方向加速度 (0.02*像素/ms^2)
	double ay;//y方向加速度 (0.02*像素/ms^2)
	point p;//像素坐标(x,y)

};

