/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * main.c
 * Copyright (C) 2016 tom <tom@tom-Latitude-E6430s>
 * 
 * lab1a is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * lab1a is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MSS 60

char * layer3(char * data_bufferPtr)
{
	printf("\nSuccessfully passsed data_bufferPtr to layer3: \n%s",data_bufferPtr);

	//dynamically create transmission_buffer to allow 480 bytes
	char *transmission_buffer = (char*)calloc(480,sizeof(char)); //allocate memory 40 frames of 120 bytes

	char local_transmission_buffer[100];
	char *zeros_buffer = (char*)calloc(40,sizeof(char));
	char *ltbPtr = &local_transmission_buffer;
	
	zeros_buffer = "0000000000000000000000000000000000000000";	 //local static char array of ascii '0' with size=40bytes
	
	/* Copy zeros_buffer to ltbPtr */
	memcpy(ltbPtr,zeros_buffer,40);  


	/* Copy 60 bytes of data_bufferPtr to ltbPtr */
	memcpy(ltbPtr+40,data_bufferPtr,60);
	printf("\nltbPtr value:\n%s",ltbPtr);


	/* Copy 100 byte ltbPtr to tbPtr */
	memcpy(transmission_buffer,ltbPtr,100);
	printf("\ntransmission_buffer: \n%s", transmission_buffer);
	
	printf("\nSize of databufferPtr %i\n",strlen(data_bufferPtr));
	
	
return data_bufferPtr;
} //Close layer3()


char * layer4()
{
	/* Declare data buffer and file pointer */
	FILE *fp;					
	static char data_buffer[2048];
	int c;
	int i;
	
	/* Open sendfile.txt */
	fp=fopen("sendfile_large.txt", "r");	//sendfile_large.txt
	if (fp == NULL) {						//check to see if file is open
		printf("file not open\n");
		return -1;
	}

	/* Put characters of sendfile.txt into data_buffer */
	for(i=0;i<sizeof(data_buffer);i=i+1)		
	{
		c = fgetc(fp);  //fgetc increments to next character
		if (feof(fp))
		{
			break;
		}
		data_buffer[i]=c;
	}

	return data_buffer;
} //Close layer4()


int main()
{

/* TRANSMIT Function */
	/* Call layer4 */
	char *data_bufferPtr;
	data_bufferPtr = layer4();
	printf("\nSuccessfully returned data_buffer from layer4: \n%s",data_bufferPtr);	//check to see if data_bufferPtr valid

	/* Call layer3 */
	char *transmission_bufferPtr;
	transmission_bufferPtr = layer3(data_bufferPtr);
	
/* Close TRANSMIT Function */

return (0);
}		//Close main()

