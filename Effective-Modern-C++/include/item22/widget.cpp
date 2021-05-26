﻿#include "gadget.h"
#include "widget.h"
#include <string>
#include <vector>

struct Widget::Impl //跟之前⼀样
{
	std::string name;
	std::vector<double> data;
	Gadget g1, g2, g3;
};

Widget::Widget()
	 :pImpl(std::make_unique<Impl>()){ } //根据Item 21, 通过std::make_shared来创建std::unique_ptr

Widget::~Widget() = default; //同上述代码效果⼀致
Widget::Widget(Widget&& rhs) = default; //在这⾥定义
Widget& Widget::operator=(Widget&& rhs) = default;

Widget::Widget(const Widget& rhs)
	:pImpl(std::make_unique<Impl>(*rhs.pImpl))
{}
Widget& Widget::operator=(const Widget& rhs)
{
	*pImpl = *rhs.pImpl;
	return *this;
}
