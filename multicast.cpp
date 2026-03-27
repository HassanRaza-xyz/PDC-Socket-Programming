#include <mpi.h>
#include <iostream>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    int data;
    if(rank == 0) data = 42; // root process
    MPI_Bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    std::cout << "Process " << rank << " received data: " << data << std::endl;
    MPI_Finalize();
    return 0;
}
