/*
 *"C++ Equivalent"
 * code
 * $ br -algorithm 'Open+Cvt(Gray)+Cascade(FrontalFace)+ASEFEyes+Affine(128,128,0.33,0.45)+(Grid(10,10)+SIFTDescriptor(12)+ByRow)/(Blur(1.1)+Gamma(0.2)+DoG(1,2)+ContrastEq(0.1,10)+LBP(1,2)+RectRegions(8,8,6,6)+Hist(59))+PCA(0.95)+Normalize(L2)+Dup(12)+RndSubspace(0.05,1)+LDA(0.98)+Cat+PCA(0.95)+Normalize(L1)+Quantize:NegativeLogPlusOne(ByteL1)' -train ../data/ATT/img FaceRecognitionATT
 *
 */

#include <openbr/openbr_plugin.h>

int main(int argc, char *argv[])
{
    br::Context::initialize(argc, argv);

    const QString trainedModelFile = "MyFaceRecognition";
    if (QFile(trainedModelFile).exists())
        return 0; // Already trained

    br::Globals->algorithm = "Open+Cvt(Gray)+Cascade(FrontalFace)+ASEFEyes+Affine(128,128,0.33,0.45)+(Grid(10,10)+SIFTDescriptor(12)+ByRow)/(Blur(1.1)+Gamma(0.2)+DoG(1,2)+ContrastEq(0.1,10)+LBP(1,2)+RectRegions(8,8,6,6)+Hist(59))+PCA(0.95)+Normalize(L2)+Dup(12)+RndSubspace(0.05,1)+LDA(0.98)+Cat+PCA(0.95)+Normalize(L1)+Quantize:NegativeLogPlusOne(ByteL1)";
    // br::Globals->algorithm = "4SF"; // Equally valid alternative. "4SF" is the abbreviation, see openbr/plugins/algorithms.cpp
    // Note the structure of the `../data/ATT/img` training data:
    //  - Subdirectory for each person
    //  - Multiple images per person
    // Run `scripts/downloadDatasets.sh` to obtain these images if you haven't already.
   const QString trainingData = "/home/user1/Downloads/openbr/data/ATT/img";     //works fine
//     const QString trainingData = "/home/user1/Downloads/all"; //illed message after long time
 
   
    // After training completes you can use `MyFaceRecognition` like `FaceRecognition`:
    //  $ br -algorithm MyFaceRecognition    // provided the `MyFaceRecognition` file is in your current working directory or in `share/openbr/models/algorithms`.
    printf("Note: Training will take at least a few minutes to complete.\n");
    br::Train(trainingData, trainedModelFile);

    br::Context::finalize();
    return 0;
}
//****************************
Note:




//after running above program MyFaceRecognition will get create.
//copy it to openbr/models/algorithms/
//then goto openbr/build/
//make
//make install
//use MyFaceRecognition in your program
