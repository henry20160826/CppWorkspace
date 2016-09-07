/*
 * Base.h
 *
 *  Created on: Aug 18, 2016
 *      Author: Administrator
 */

#ifndef BASE_H_
#define BASE_H_


void print(int *p, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << *(p + i) << " ";
	}
	std::cout << std::endl;
}

#endif /* BASE_H_ */
