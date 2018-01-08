#pragma once

#include "stdafx.h"

#include "WordBase.h"

class Articles2 :
	public WordBase
{
public:
	Articles2(Articles2 const&) = delete;
	void operator=(Articles2 const&) = delete;
	~Articles2();

	static Articles2& getInstance();

private:
	Articles2();

};