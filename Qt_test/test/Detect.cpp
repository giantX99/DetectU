#include "Detect.h"


void Detect::set_up() {
    std::string file_path = "C:/Users/nhoei/ComputerVision/opencvGPU/";
    std::vector<std::string> class_names;
    std::ifstream ifs(std::string(file_path + "object_detection_classes_coco.txt").c_str());
    std::string line;

    // Load in all the classes from the file
    while (getline(ifs, line))
    {   
        std::cout << line << std::endl;
        class_names.push_back(line);
    } 
    

    // Read in the neural network from the files
    auto net = cv::dnn::readNet(file_path + "frozen_inference_graph.pb",
    file_path + "ssd_mobilenet_v2_coco_2018_03_29.pbtxt.txt","TensorFlow");
 

    // Open up the webcam
    cv::VideoCapture cap(0);
 

    // Run on either CPU or GPU
    //net.setPreferableBackend(DNN_BACKEND_CUDA);
    //net.setPreferableTarget(DNN_TARGET_CUDA);


    // Set a min confidence score for the detections
    float min_confidence_score = 0.5;
}

void Detect::start() {
    set_up();

    //DETECTION CODE:

    // Load in an image
        cv::Mat image;
        bool isSuccess = cap.read(image); //cap defined in set_up() SOLVE THIS!

        // Check if image is loaded in correctly
        if (!isSuccess){
            std::cout << "Could not load the image!" << std::endl;
            //INSERT ERROR HANDLING HERE!!
        }
        
        int image_height = image.cols;
        int image_width = image.rows;



        auto start = cv::getTickCount();

        // Create a blob from the image
        cv::Mat blob = cv::dnn::blobFromImage(image, 1.0, cv::Size(300, 300), cv::Scalar(127.5, 127.5, 127.5),
                                true, false);

        
        // Set the blob to be input to the neural network
        net.setInput(blob); //net defined in set_up() SOLVE THIS!

        // Forward pass of the blob through the neural network to get the predictions
        cv::Mat output = net.forward();

        auto end = cv::getTickCount();
        


        // Matrix with all the detections
        cv::Mat results(output.size[2], output.size[3], CV_32F, output.ptr<float>());
        
        // Run through all the predictions
        for (int i = 0; i < results.rows; i++){
            int class_id = int(results.at<float>(i, 1));
            float confidence = results.at<float>(i, 2);
    
            // Check if the detection is over the min threshold and then draw bbox
            if (confidence > min_confidence_score){ //min_confidence_score defined in set_up() SOLVE THIS!
                int bboxX = int(results.at<float>(i, 3) * image.cols);
                int bboxY = int(results.at<float>(i, 4) * image.rows);
                int bboxWidth = int(results.at<float>(i, 5) * image.cols - bboxX);
                int bboxHeight = int(results.at<float>(i, 6) * image.rows - bboxY);
                cv::rectangle(image, cv::Point(bboxX, bboxY), cv::Point(bboxX + bboxWidth, bboxY + bboxHeight), cv::Scalar(0,0,255), 2);
                std::string class_name = class_names[class_id-1]; //class_names defined in set_up() SOLVE THIS!
                cv::putText(image, class_name + " " + std::to_string(int(confidence*100)) + "%", cv::Point(bboxX, bboxY - 10), cv::FONT_HERSHEY_SIMPLEX, 1.5, cv::Scalar(0,255,0), 2);
            }
        }
        

        auto totalTime = (end - start) / cv::getTickFrequency();
        

        cv::putText(image, "FPS: " + std::to_string(int(1 / totalTime)), cv::Point(50, 50), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(0, 255, 0), 2, false);
        

}

void Detect::stop() {

}