__kernel void next_direction( __global float * position_x, __global float * position_y, __global float * direction_x, __global float *direction_y, __global float *velocity, __global int *color, float radius_repulsion ,float radius_attraction)
{
	int tid=get_global_id(0);
	int size =get_global_size(0);
	float new_direction_x1=0.0f,new_direction_y1=0.0f, new_direction_x2=0.0f,new_direction_y2=0.0f;
	float dist_x,dist_y,dist;
	int i,flag=0;
	int flag_neighbour=0;
	float mod;
	for(i=0;i<size;i++)
	{
		if(i!=tid)
		{
			dist_x=(position_x[i]-position_x[tid]);
			dist_y=(position_y[i]-position_y[tid]);
			if(dist_x<0.0f)
				dist_x=-dist_x;
			if(dist_y<0.0f)
				dist_y=-dist_y;
			dist=(dist_x*dist_x)+(dist_y*dist_y);
			if(dist_x<=radius_repulsion||dist_y<=radius_repulsion)
			{
				if((dist)<=(radius_repulsion*radius_repulsion))
				{ 
					new_direction_x1-=direction_x[i];
					new_direction_y1-=direction_y[i];
					flag=1;
				}
			}

			else if(!flag&&(dist_x<=radius_attraction||dist_y<=radius_attraction)&&(color[tid]==color[i]))
			{ 
				if((dist)<=(radius_attraction*radius_attraction))
				{ 
					new_direction_x2+=direction_x[i];
					new_direction_y2+=direction_y[i];
					flag_neighbour=1;
				}
			}

		}
	}
	if(flag)
	{
		mod=sqrt((new_direction_x1*new_direction_x1)+(new_direction_y1*new_direction_y1));
		direction_x[tid]=new_direction_x1/mod;
		direction_y[tid]=new_direction_y1/mod;
	}
	else if(flag_neighbour)
	{ 
		mod=sqrt((new_direction_x2*new_direction_x2)+(new_direction_y2*new_direction_y2));
		direction_x[tid]=new_direction_x2/mod;
		direction_y[tid]=new_direction_y2/mod;
	}
}
