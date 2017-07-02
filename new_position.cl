__kernel void next_position( __global float * position_x, __global float * position_y, __global float * direction_x, __global float *direction_y, __global float *velocity, float delta_time )
{
	int tid=get_global_id(0);
	float new_position_x,new_position_y;
	int flag=1;
	new_position_x= position_x[tid] + (direction_x[tid] * velocity[tid] * delta_time);
	new_position_y= position_y[tid] + (direction_y[tid] * velocity[tid] * delta_time);
	//if(tid<20)
		//printf("tid=%d position_x[tid]=%f position_y[tid]=%f new_position_x=%f new_position_y=%f ,\n",tid,position_x[tid],position_y[tid],new_position_x,new_position_y);
	while(flag!=2)
	{
		flag++;
		if((new_position_x) <= -1.0f )
		{
			direction_x[tid] = -direction_x[tid];
			new_position_x = -1.0f + (new_position_x - 1.0f);
			flag=1;
	 	}
		else if ((new_position_y) <= -1.0f)
		{
			direction_y[tid] = -direction_y[tid];
			new_position_y =-1.0f + (new_position_y - 1.0f);
			flag=1;
		}
		else if ((new_position_x) >= 1.0f)
		{
			direction_x[tid] = -direction_x[tid];
			new_position_x = 1.0f - (new_position_x -1.0f);
			flag=1;
		}
		else if ((new_position_y) >= 1.0f)
		{
			direction_y[tid] = -direction_y[tid];
			new_position_y = 1.0f - (new_position_y - 1.0f);
			flag=1;
		}
	}
	position_x[tid]=new_position_x;
	position_y[tid]=new_position_y;
}