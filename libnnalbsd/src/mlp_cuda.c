__global__ void mlp_cuda_execute() 
{ 
    // Block index 
    int bx = blockIdx.x; 
    int by = blockIdx.y; 
 
    // Thread index 
    int tx = threadIdx.x; 
    int ty = threadIdx.y; 
	
	__syncthreads(); 
}         
