__kernel void copy_value( __global float *position_x,__global float *position_y ,__global float *vertices, int offset)
{
	int tid=get_global_id(0);
	if(tid%2==0)
		vertices[tid]=position_x[offset+tid/2];
	else
		vertices[tid]=position_y[offset+tid/2];
}
