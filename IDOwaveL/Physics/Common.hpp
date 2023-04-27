#pragma once

class ifj {
public:
	static long long get_nanotime();
};

static long long timeStarted = ifj::get_nanotime();

class Time
{
public:
	static float getTime();
};