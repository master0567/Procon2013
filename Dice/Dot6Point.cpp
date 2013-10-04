#include "Dot6Point.h"

namespace pro{

Dot6Point::Dot6Point(void)
{
}


Dot6Point::~Dot6Point(void)
{
}

void Dot6Point::setCenter(){
	double x,y;
	double dx,dy;
	double minx,miny;
	
	// 小さい座標を保存
	minx = dot3[0].center.pt.x;
	miny = dot3[0].center.pt.y;
	if(minx > dot3[1].center.pt.x) minx = dot3[1].center.pt.x; 
	if(miny > dot3[1].center.pt.y) miny = dot3[1].center.pt.y; 

	// 距離を求める
	dx = abs(dot3[0].center.pt.x-dot3[1].center.pt.x);
	dy = abs(dot3[0].center.pt.y-dot3[1].center.pt.y);

	// 座標取得
	if(dx < sqrt(dot3[0].center.size/CV_PI))
		x = dot3[0].center.pt.x;
	else
		x = minx + dx/2;
	if(dy < sqrt(dot3[0].center.size/CV_PI))
		y = dot3[0].center.pt.y;
	else
		y = miny + dy/2;

	// center決定
	center.init(x,y,dot3[0].center.size);
}

void Dot6Point::init(Dot3Point dot3p1,Dot3Point dot3p2,DiceInfo::dtype type){
	this->type = type;
	dot3[0].init(dot3p1);
	dot3[1].init(dot3p2);
	setCenter();
}

void Dot6Point::draw(Image& img,cv::Scalar dot_col,cv::Scalar line_col,int thickness){
	dot3[0].draw(img,dot_col,line_col,thickness);
	dot3[1].draw(img,dot_col,line_col,thickness);
}

void Dot6Point::drawCenter(Image& img,cv::Scalar scal){
	center.draw(img,scal);
}

}