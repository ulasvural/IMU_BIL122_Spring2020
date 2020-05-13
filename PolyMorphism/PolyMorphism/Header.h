#pragma once
#include <iostream>

using namespace std;

class A {
public:
	A();// = default;
	void nonVirt() const;
	virtual void virt() const;
	virtual ~A();// = default;
};


class B :public A {
public:
	B();// = default;
	void nonVirt() const;
	virtual void virt() const override;
	virtual ~B();// = default;
};


class C : public B {
public:
	C();// = default;
	void nonVirt() const;
	virtual void virt() const override final;
	void cSpecial() const;
	void cSpecialVirt() const;
	virtual ~C();// = default;
};

class D : public C {
public:
	D();// = default;
	void nonVirt() const;
	//virtual void virt() const override;  // Compiler Error: Cannot override 'final' function C::virt
	virtual ~D();// = default;
};