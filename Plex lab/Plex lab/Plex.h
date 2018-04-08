#pragma once
#include <stack>

using namespace std;
using namespace System::Drawing;

class TRoot{
protected:
	bool visible;
	bool active;
public:
	TRoot(bool _visible = true, bool _active = false) {
		visible = _visible;
		active = _active;
	}

	virtual void Show(Graphics ^gr) = 0;
	virtual void Hide(Graphics ^gr) = 0;
	virtual void Move(Graphics ^gr, int dx, int dy) = 0;
};



class TPoint : public TRoot {
//protected:
public:
	int x;
	int y;
public:
	TPoint(int _x = 0, int _y = 0) : TRoot() {
		x = _x;
		y = _y;
	}

	virtual void Show(Graphics ^gr);
	virtual void Hide(Graphics ^gr);
	virtual void Move(Graphics ^gr, int dx, int dy);
};



struct TCurrLine {
	TRoot *ct;
	TPoint *pb;
	TPoint *pe;
};



class TChart :public TRoot {
protected:
	TRoot *pBegin;
	TRoot *pEnd;
	stack<TCurrLine> st;
public:
	TChart(TRoot *pb = nullptr, TRoot *pe = nullptr);

	void SetBegin(TRoot *pb);
	void SetEnd(TRoot *pe);

	TRoot *GetBegin() { return pBegin; }
	TRoot *GetEnd() { return pEnd; }

	TRoot *Show(Graphics ^gr, TRoot *curr);

	virtual void Show(Graphics ^gr) {}
	virtual void Hide(Graphics ^gr) {}
	virtual void Move(Graphics ^gr, int dx, int dy) {}
};