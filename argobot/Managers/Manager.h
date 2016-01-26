#pragma once

class Manager
{
public:
	virtual ~Manager();
	virtual void onStart() = 0;
};

