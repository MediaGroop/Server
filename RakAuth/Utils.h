#pragma once

bool compareHashes(unsigned char* arr1, unsigned char* arr2)
{
	for (int i = 0; i < 20; ++i)
	{
		if (arr1[i] != arr2[i])
			return false;
	}
	return true;
}