#pragma once

class FString
{
private:
	int len;
	char* buf;
public:
	FString(unsigned int length);
	~FString();
	FString(const FString &str);
	void show();

};