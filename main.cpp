/**
 * @file main.cpp
 * @author Prajeeth Naliganti
 */

#include <iostream>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization//cloud_viewer.h>
#include <boost/thread/thread.hpp>
#include <chrono>
#include <thread>



using namespace std;
using namespace pcl;


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
//    for (const auto& point : *cloud)
//    {
//        cout << "x: " << point.x << ", y: " << point.y << ", z: " << point.z << endl;
//    }

    //use PCL Visualizer
    pcl::visualization::PCLVisualizer::Ptr visualizer(new pcl::visualization::PCLVisualizer("Point Cloud Viewer"));

    //Add the point cloud to visualizer
    visualizer->addPointCloud(cloud, "cloud");

    //set the coordinate system
    visualizer->addCoordinateSystem(1.0);

    //wait for viewer class to be closed by user
    while(!visualizer->wasStopped())
    {
        try {
            visualizer->spinOnce(100);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        } catch (const std::exception& e) {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        } catch (...) {
            std::cerr << "Caught unknown exception." << std::endl;
        }
    }

    return 0;
}

