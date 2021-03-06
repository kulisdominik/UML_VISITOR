// UML_VISITOR.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <memory>

class AbstractVisitor;

class Gate {
public:
	virtual void accept(AbstractVisitor &v) = 0;
};

class OrGate;
class AndGate;

class AbstractVisitor
{
public:
	virtual void visit(OrGate &orGate) = 0;
	virtual void visit(AndGate &andGate) = 0;
};

class OrGate : public Gate
{
public:
	void accept(AbstractVisitor &v) override
	{
		v.visit(*this);
	}
};

class AndGate : public Gate
{
public:
	void accept(AbstractVisitor &v) override
	{
		v.visit(*this);
	}
};

class Visitor : public AbstractVisitor
{
public:
	void visit(OrGate &orGate)
	{
		std::cout << "OrGate" << std::endl;
	}

	void visit(AndGate &andGate)
	{
		std::cout << "AndGate" << std::endl;
	}
};
int main()
{
	std::vector<std::unique_ptr<Gate>> gates;
	gates.emplace_back(std::make_unique<OrGate>());
	gates.emplace_back(std::make_unique<AndGate>());

	Visitor visitor;

	for (auto& gate : gates)
	{
		gate->accept(visitor);
	}
    
	
	return 0;
}

