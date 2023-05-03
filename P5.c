#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#define NOF_PACKETS 10

int rand(int a)
{
int rn = (random() % 10) % a;
return rn == 0 ? 1 : rn;
}



int main()
{
int packet_sz[NOF_PACKETS], i, clk, b_size, o_rate, p_sz_rm=0, p_sz, p_time, op;
for(i = 0; i<NOF_PACKETS; ++i)
packet_sz[i] = rand(6) * 10;
for(i = 0; i<NOF_PACKETS; ++i)
printf("\npacket[%d]:%d bytes\t", i, packet_sz[i]);
printf("\nEnter the Output rate:");
scanf("%d", &o_rate);
printf("Enter the Bucket Size:");
scanf("%d", &b_size);
for(i = 0; i<NOF_PACKETS; ++i)
{
if( (packet_sz[i] + p_sz_rm) > b_size)
if(packet_sz[i] > b_size)/*compare the packet siz with bucket size*/
printf("\n\nIncoming packet size (%dbytes) is Greater than bucket capacity (%dbytes)-PACKET REJECTED", packet_sz[i], b_size);
else
printf("\n\nBucket capacity exceeded-PACKETS REJECTED!!");
else
{
p_sz_rm += packet_sz[i];
printf("\n\nIncoming Packet size: %d", packet_sz[i]);
printf("\nBytes remaining to Transmit: %d", p_sz_rm);
p_time = rand(4) * 10;
printf("\nTime left for transmission: %d units", p_time);
for(clk = 10; clk <= p_time; clk += 10)
{
sleep(1);
if(p_sz_rm)
{
if(p_sz_rm <= o_rate)/*packet size remaining comparing with output rate*/
op = p_sz_rm, p_sz_rm = 0;
else
op = o_rate, p_sz_rm -= o_rate;
printf("\nPacket of size %d Transmitted", op);
printf("----Bytes Remaining to Transmit: %d", p_sz_rm);
}
else
{
printf("\nTime left for transmission: %d units", p_time-clk);
printf("\nNo packets to transmit!!");
}
}
}
}
}

// method 2

#include <stdio.h>
void main()
{
	int no_of_queries, storage, output_pkt_size;
	int input_pkt_size, bucket_size, size_left;
	storage = 0;
	no_of_queries = 4;
	bucket_size = 10;
	input_pkt_size = 4;
	output_pkt_size = 1;
	for (int i = 0; i < no_of_queries; i++) 
	{
		size_left = bucket_size - storage;
		if (input_pkt_size <= size_left) {
			storage += input_pkt_size;
		}
		else {
			printf("Packet loss = %d\n", input_pkt_size);
		}
		printf("Buffer size= %d out of bucket size= %d\n",
			storage, bucket_size);
		storage -= output_pkt_size;
	}
	return 0;
}
