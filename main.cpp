/**
 * @file main.cpp
 * @author Prajeeth Naliganti
 */

#include <iostream>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>

using namespace std;
using namespace pcl;
namespace pcl_io
{

}

int main()
{
    std::cout << PCL_VERSION << std::endl;

    //Define point cloud type
    PointCloud<PointXYZ>::Ptr cloud(new PointCloud<PointXYZ>);

    //Load PCD file
    if (pcl::io::loadPCDFile<PointXYZ>("/Users/prajeethnaliganti/Desktop/AI Models/AutonomousVehicle/PCL Files/SampleScan.pcd", *cloud) == -1)
    {
        PCL_ERROR("Couldn't read the PCD file.\n");
        return -1;
    }

    // Print information about loaded point cloud
    cout << "Loaded a point cloud with" << cloud->width * cloud->height << "data points." << endl;

    // Access the point cloud data
    for (const auto& point : *cloud)
    {
        cout << "x: " << point.x << ", y: " << point.y << ", z: " << point.z << endl;
    }

    return 0;
}

