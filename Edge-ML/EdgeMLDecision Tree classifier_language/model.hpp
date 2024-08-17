#ifndef EDGEMLPIPELINE_HPP
#define EDGEMLPIPELINE_HPP

#include <vector>
#include <string>

    #include "feature_extractor.hpp"


#define Matrix vector<vector<float>>




    int ctr = 0;

    Matrix step_0_output(3, vector<float>(125));

    Matrix step_1_output(3, vector<float>(9));

    Matrix step_2_output(3, vector<float>(9));


float get_sampling_rate() {
    return 1000.0;
}

string class_to_label(int cls) {
    
        if (cls == 0) {
            return "DWS";
        }
    
        if (cls == 1) {
            return "JOG";
        }
    
        if (cls == 2) {
            return "SIT";
        }
    
        if (cls == 3) {
            return "STD";
        }
    
        if (cls == 4) {
            return "UPS";
        }
    
        if (cls == 5) {
            return "WLK";
        }
    
    return "";
}



    void add_datapoint(float accX,float accY,float accZ)
    {
        int window_size = 125;

        
            step_0_output[0][ctr] = accX;
        
            step_0_output[1][ctr] = accY;
        
            step_0_output[2][ctr] = accZ;
        
        ctr++;
        if (ctr >= window_size)
        {
            ctr = 0;
        }
    }

    void step_1(Matrix &inputs, Matrix &outputs)
{
    int num_sensors = 3;
    int num_features = 9;

    for (int i = 0; i < num_sensors; i++)
    {
        outputs[i][0] = sum(inputs[i]);
        outputs[i][1] = median(inputs[i]);
        outputs[i][2] = mean(inputs[i]);
        outputs[i][3] = standard_deviation(inputs[i]);
        outputs[i][4] = variance(inputs[i]);
        outputs[i][5] = max(inputs[i]);
        outputs[i][6] = abs_max(inputs[i]);
        outputs[i][7] = min(inputs[i]);
        outputs[i][8] = abs_min(inputs[i]);
    }
}

    Matrix mins = {
    {-86.40098837204278, -0.6053919792175293, -0.6912079069763422, 0.0010951530680633815, 1.1993602424886377e-06, -0.5638729929924011, 4.600000102072954e-05, -3.394745111465454, 0.00019799999427050352},
    {-133.41862724535167, -1.09033203125, -1.0673490179628133, 0.0011761045023957646, 1.383221800555589e-06, -0.9934689998626709, 9.200000204145908e-05, -4.019134998321533, 3.099999958067201e-05},
    {-126.18962502479553, -1.009948968887329, -1.0095170001983642, 0.0012140577292217276, 1.4739361698830179e-06, -1.0005489587783813, 0.0, -6.351395130157471, 0.0},
};
Matrix maxs = {
    {104.65335322916508, 0.8456270098686218, 0.8372268258333206, 0.9274504821000915, 0.8601643967476921, 3.223510980606079, 3.223510980606079, 0.5102229714393616, 3.394745111465454},
    {159.8577250316739, 1.33502197265625, 1.2788618002533914, 2.0714563284374874, 4.290931320623716, 7.938370227813721, 7.938370227813721, 0.9983059763908386, 4.019134998321533},
    {108.37897002696991, 0.8717039823532104, 0.8670317602157592, 1.2651865204879806, 1.6006969316244832, 5.158173084259033, 5.158173084259033, 0.8469240069389343, 6.351395130157471},
};

void step_2(Matrix &input, Matrix &outputs)
{
    int num_sensors = input.size();
    int feature_size = input[0].size();
    for (int i = 0; i < num_sensors; i++)
    {
        for (int j = 0; j < feature_size; j++)
        {
            outputs[i][j] = (input[i][j] - mins[i][j]) / (maxs[i][j] - mins[i][j]);
        }
    }
}

    
int step_3(Matrix &features) {
    int num_sensors = features.size();
    int num_features = features[0].size();
    
    if (features[15 / num_features][15 % num_features] <= 0.09984463453292847) {
        
            
    if (features[13 / num_features][13 % num_features] <= 0.029507079860195518) {
        
            
    return 2;

        
    }
    else {
        
            
    return 4;

        
    }

        
    }
    else {
        
            
    if (features[12 / num_features][12 % num_features] <= 0.05974634923040867) {
        
            
    return 3;

        
    }
    else {
        
            
    if (features[13 / num_features][13 % num_features] <= 0.19533971697092056) {
        
            
    if (features[14 / num_features][14 % num_features] <= 0.3408287465572357) {
        
            
    if (features[10 / num_features][10 % num_features] <= 0.8405169248580933) {
        
            
    if (features[2 / num_features][2 % num_features] <= 0.6442307233810425) {
        
            
    if (features[19 / num_features][19 % num_features] <= 0.6949421465396881) {
        
            
    if (features[2 / num_features][2 % num_features] <= 0.07425477728247643) {
        
            
    return 5;

        
    }
    else {
        
            
    if (features[17 / num_features][17 % num_features] <= 0.002182949217967689) {
        
            
    if (features[22 / num_features][22 % num_features] <= 0.06161334924399853) {
        
            
    return 0;

        
    }
    else {
        
            
    return 4;

        
    }

        
    }
    else {
        
            
    if (features[10 / num_features][10 % num_features] <= 0.8354335129261017) {
        
            
    if (features[14 / num_features][14 % num_features] <= 0.3367713987827301) {
        
            
    if (features[22 / num_features][22 % num_features] <= 0.03126703388988972) {
        
            
    if (features[16 / num_features][16 % num_features] <= 0.8187247216701508) {
        
            
    return 0;

        
    }
    else {
        
            
    if (features[13 / num_features][13 % num_features] <= 0.010736213065683842) {
        
            
    if (features[7 / num_features][7 % num_features] <= 0.6782911121845245) {
        
            
    return 4;

        
    }
    else {
        
            
    return 0;

        
    }

        
    }
    else {
        
            
    if (features[12 / num_features][12 % num_features] <= 0.16372088342905045) {
        
            
    return 4;

        
    }
    else {
        
            
    if (features[10 / num_features][10 % num_features] <= 0.8218913674354553) {
        
            
    return 4;

        
    }
    else {
        
            
    return 0;

        
    }

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    if (features[10 / num_features][10 % num_features] <= 0.8348358869552612) {
        
            
    if (features[21 / num_features][21 % num_features] <= 0.20198694616556168) {
        
            
    if (features[20 / num_features][20 % num_features] <= 0.4025069922208786) {
        
            
    return 0;

        
    }
    else {
        
            
    if (features[16 / num_features][16 % num_features] <= 0.7861890196800232) {
        
            
    return 0;

        
    }
    else {
        
            
    if (features[19 / num_features][19 % num_features] <= 0.6683764159679413) {
        
            
    if (features[10 / num_features][10 % num_features] <= 0.8268774151802063) {
        
            
    return 4;

        
    }
    else {
        
            
    if (features[3 / num_features][3 % num_features] <= 0.1658124402165413) {
        
            
    if (features[26 / num_features][26 % num_features] <= 0.052476268261671066) {
        
            
    return 4;

        
    }
    else {
        
            
    return 0;

        
    }

        
    }
    else {
        
            
    if (features[15 / num_features][15 % num_features] <= 0.246859572827816) {
        
            
    return 4;

        
    }
    else {
        
            
    if (features[22 / num_features][22 % num_features] <= 0.03865993767976761) {
        
            
    return 0;

        
    }
    else {
        
            
    return 4;

        
    }

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    if (features[1 / num_features][1 % num_features] <= 0.30862586200237274) {
        
            
    return 0;

        
    }
    else {
        
            
    return 4;

        
    }

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    if (features[10 / num_features][10 % num_features] <= 0.8225803375244141) {
        
            
    return 4;

        
    }
    else {
        
            
    if (features[10 / num_features][10 % num_features] <= 0.8226339221000671) {
        
            
    if (features[8 / num_features][8 % num_features] <= 0.29138968139886856) {
        
            
    return 4;

        
    }
    else {
        
            
    return 0;

        
    }

        
    }
    else {
        
            
    return 4;

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    if (features[0 / num_features][0 % num_features] <= 0.47000113129615784) {
        
            
    return 4;

        
    }
    else {
        
            
    return 5;

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    if (features[14 / num_features][14 % num_features] <= 0.33873002231121063) {
        
            
    return 0;

        
    }
    else {
        
            
    return 4;

        
    }

        
    }

        
    }
    else {
        
            
    if (features[8 / num_features][8 % num_features] <= 0.16901090741157532) {
        
            
    if (features[7 / num_features][7 % num_features] <= 0.7504534125328064) {
        
            
    return 0;

        
    }
    else {
        
            
    if (features[3 / num_features][3 % num_features] <= 0.2730748802423477) {
        
            
    return 4;

        
    }
    else {
        
            
    return 5;

        
    }

        
    }

        
    }
    else {
        
            
    if (features[1 / num_features][1 % num_features] <= 0.35343436896800995) {
        
            
    if (features[22 / num_features][22 % num_features] <= 0.02873506210744381) {
        
            
    return 0;

        
    }
    else {
        
            
    if (features[9 / num_features][9 % num_features] <= 0.8373892903327942) {
        
            
    return 0;

        
    }
    else {
        
            
    return 4;

        
    }

        
    }

        
    }
    else {
        
            
    return 0;

        
    }

        
    }

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    if (features[18 / num_features][18 % num_features] <= 0.7146659791469574) {
        
            
    return 0;

        
    }
    else {
        
            
    if (features[20 / num_features][20 % num_features] <= 0.7594282627105713) {
        
            
    return 4;

        
    }
    else {
        
            
    return 2;

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    return 0;

        
    }

        
    }
    else {
        
            
    if (features[23 / num_features][23 % num_features] <= 0.25262869894504547) {
        
            
    if (features[20 / num_features][20 % num_features] <= 0.49786514043807983) {
        
            
    if (features[5 / num_features][5 % num_features] <= 0.2169291451573372) {
        
            
    if (features[22 / num_features][22 % num_features] <= 0.06259425450116396) {
        
            
    return 0;

        
    }
    else {
        
            
    return 4;

        
    }

        
    }
    else {
        
            
    if (features[4 / num_features][4 % num_features] <= 0.0990724228322506) {
        
            
    if (features[7 / num_features][7 % num_features] <= 0.5814037919044495) {
        
            
    return 0;

        
    }
    else {
        
            
    return 4;

        
    }

        
    }
    else {
        
            
    return 5;

        
    }

        
    }

        
    }
    else {
        
            
    if (features[8 / num_features][8 % num_features] <= 0.12179223820567131) {
        
            
    return 5;

        
    }
    else {
        
            
    return 0;

        
    }

        
    }

        
    }
    else {
        
            
    if (features[1 / num_features][1 % num_features] <= 0.46953001618385315) {
        
            
    if (features[12 / num_features][12 % num_features] <= 0.225156769156456) {
        
            
    if (features[18 / num_features][18 % num_features] <= 0.6439096927642822) {
        
            
    if (features[0 / num_features][0 % num_features] <= 0.27386337518692017) {
        
            
    return 4;

        
    }
    else {
        
            
    return 0;

        
    }

        
    }
    else {
        
            
    if (features[26 / num_features][26 % num_features] <= 0.08356014266610146) {
        
            
    return 4;

        
    }
    else {
        
            
    return 0;

        
    }

        
    }

        
    }
    else {
        
            
    return 5;

        
    }

        
    }
    else {
        
            
    if (features[19 / num_features][19 % num_features] <= 0.5455984473228455) {
        
            
    return 4;

        
    }
    else {
        
            
    return 0;

        
    }

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    if (features[20 / num_features][20 % num_features] <= 0.6198886036872864) {
        
            
    if (features[19 / num_features][19 % num_features] <= 0.5061995983123779) {
        
            
    if (features[1 / num_features][1 % num_features] <= 0.4252687096595764) {
        
            
    if (features[2 / num_features][2 % num_features] <= 0.2850940078496933) {
        
            
    if (features[16 / num_features][16 % num_features] <= 0.7409563958644867) {
        
            
    return 5;

        
    }
    else {
        
            
    if (features[12 / num_features][12 % num_features] <= 0.23655875772237778) {
        
            
    return 4;

        
    }
    else {
        
            
    return 0;

        
    }

        
    }

        
    }
    else {
        
            
    return 0;

        
    }

        
    }
    else {
        
            
    if (features[23 / num_features][23 % num_features] <= 0.2957944720983505) {
        
            
    if (features[16 / num_features][16 % num_features] <= 0.7970458567142487) {
        
            
    if (features[0 / num_features][0 % num_features] <= 0.7032033801078796) {
        
            
    return 4;

        
    }
    else {
        
            
    return 1;

        
    }

        
    }
    else {
        
            
    if (features[12 / num_features][12 % num_features] <= 0.20770888775587082) {
        
            
    if (features[9 / num_features][9 % num_features] <= 0.8613217771053314) {
        
            
    return 4;

        
    }
    else {
        
            
    return 5;

        
    }

        
    }
    else {
        
            
    if (features[7 / num_features][7 % num_features] <= 0.7580203115940094) {
        
            
    return 4;

        
    }
    else {
        
            
    return 1;

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    if (features[8 / num_features][8 % num_features] <= 0.2759963124990463) {
        
            
    if (features[1 / num_features][1 % num_features] <= 0.6510503888130188) {
        
            
    if (features[1 / num_features][1 % num_features] <= 0.5610232949256897) {
        
            
    if (features[4 / num_features][4 % num_features] <= 0.21912097930908203) {
        
            
    return 5;

        
    }
    else {
        
            
    return 0;

        
    }

        
    }
    else {
        
            
    return 4;

        
    }

        
    }
    else {
        
            
    return 1;

        
    }

        
    }
    else {
        
            
    if (features[13 / num_features][13 % num_features] <= 0.15048666298389435) {
        
            
    return 0;

        
    }
    else {
        
            
    return 1;

        
    }

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    if (features[1 / num_features][1 % num_features] <= 0.568895012140274) {
        
            
    if (features[25 / num_features][25 % num_features] <= 0.3597400337457657) {
        
            
    if (features[15 / num_features][15 % num_features] <= 0.4929753690958023) {
        
            
    return 5;

        
    }
    else {
        
            
    return 0;

        
    }

        
    }
    else {
        
            
    if (features[3 / num_features][3 % num_features] <= 0.2663012892007828) {
        
            
    if (features[2 / num_features][2 % num_features] <= 0.32994458079338074) {
        
            
    return 4;

        
    }
    else {
        
            
    if (features[13 / num_features][13 % num_features] <= 0.06395192816853523) {
        
            
    if (features[16 / num_features][16 % num_features] <= 0.87412229180336) {
        
            
    return 0;

        
    }
    else {
        
            
    return 5;

        
    }

        
    }
    else {
        
            
    if (features[15 / num_features][15 % num_features] <= 0.37632788717746735) {
        
            
    return 5;

        
    }
    else {
        
            
    return 0;

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    if (features[8 / num_features][8 % num_features] <= 0.28338611125946045) {
        
            
    if (features[19 / num_features][19 % num_features] <= 0.5941972136497498) {
        
            
    if (features[19 / num_features][19 % num_features] <= 0.5127316415309906) {
        
            
    if (features[16 / num_features][16 % num_features] <= 0.8014266788959503) {
        
            
    if (features[23 / num_features][23 % num_features] <= 0.2944851219654083) {
        
            
    return 4;

        
    }
    else {
        
            
    return 0;

        
    }

        
    }
    else {
        
            
    if (features[3 / num_features][3 % num_features] <= 0.3086751401424408) {
        
            
    return 4;

        
    }
    else {
        
            
    return 5;

        
    }

        
    }

        
    }
    else {
        
            
    if (features[18 / num_features][18 % num_features] <= 0.4640001207590103) {
        
            
    return 0;

        
    }
    else {
        
            
    if (features[5 / num_features][5 % num_features] <= 0.2645803838968277) {
        
            
    return 4;

        
    }
    else {
        
            
    if (features[11 / num_features][11 % num_features] <= 0.9194819331169128) {
        
            
    if (features[9 / num_features][9 % num_features] <= 0.9112430214881897) {
        
            
    if (features[19 / num_features][19 % num_features] <= 0.51357501745224) {
        
            
    if (features[9 / num_features][9 % num_features] <= 0.8931912481784821) {
        
            
    if (features[4 / num_features][4 % num_features] <= 0.08469116315245628) {
        
            
    return 4;

        
    }
    else {
        
            
    return 5;

        
    }

        
    }
    else {
        
            
    if (features[21 / num_features][21 % num_features] <= 0.3022284060716629) {
        
            
    return 4;

        
    }
    else {
        
            
    return 0;

        
    }

        
    }

        
    }
    else {
        
            
    if (features[4 / num_features][4 % num_features] <= 0.08432238548994064) {
        
            
    if (features[26 / num_features][26 % num_features] <= 0.2609977051615715) {
        
            
    if (features[16 / num_features][16 % num_features] <= 0.7213958501815796) {
        
            
    return 0;

        
    }
    else {
        
            
    return 5;

        
    }

        
    }
    else {
        
            
    return 0;

        
    }

        
    }
    else {
        
            
    if (features[11 / num_features][11 % num_features] <= 0.9052869081497192) {
        
            
    if (features[11 / num_features][11 % num_features] <= 0.9025467932224274) {
        
            
    return 5;

        
    }
    else {
        
            
    if (features[11 / num_features][11 % num_features] <= 0.9025627076625824) {
        
            
    return 0;

        
    }
    else {
        
            
    return 5;

        
    }

        
    }

        
    }
    else {
        
            
    if (features[11 / num_features][11 % num_features] <= 0.9053105711936951) {
        
            
    return 0;

        
    }
    else {
        
            
    if (features[20 / num_features][20 % num_features] <= 0.5117014944553375) {
        
            
    return 5;

        
    }
    else {
        
            
    if (features[5 / num_features][5 % num_features] <= 0.3231133967638016) {
        
            
    return 5;

        
    }
    else {
        
            
    return 0;

        
    }

        
    }

        
    }

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    if (features[3 / num_features][3 % num_features] <= 0.2982759475708008) {
        
            
    return 0;

        
    }
    else {
        
            
    if (features[25 / num_features][25 % num_features] <= 0.6455296874046326) {
        
            
    return 5;

        
    }
    else {
        
            
    return 0;

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    if (features[17 / num_features][17 % num_features] <= 0.14944786950945854) {
        
            
    return 0;

        
    }
    else {
        
            
    return 5;

        
    }

        
    }

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    return 0;

        
    }

        
    }
    else {
        
            
    if (features[6 / num_features][6 % num_features] <= 0.19677117466926575) {
        
            
    if (features[13 / num_features][13 % num_features] <= 0.05065588280558586) {
        
            
    if (features[25 / num_features][25 % num_features] <= 0.6980958580970764) {
        
            
    if (features[10 / num_features][10 % num_features] <= 0.8351411819458008) {
        
            
    return 5;

        
    }
    else {
        
            
    return 0;

        
    }

        
    }
    else {
        
            
    if (features[8 / num_features][8 % num_features] <= 0.37690654397010803) {
        
            
    return 0;

        
    }
    else {
        
            
    return 4;

        
    }

        
    }

        
    }
    else {
        
            
    if (features[25 / num_features][25 % num_features] <= 0.7203322052955627) {
        
            
    if (features[17 / num_features][17 % num_features] <= 0.01790822111070156) {
        
            
    return 0;

        
    }
    else {
        
            
    if (features[7 / num_features][7 % num_features] <= 0.5574290454387665) {
        
            
    return 5;

        
    }
    else {
        
            
    if (features[7 / num_features][7 % num_features] <= 0.5677332282066345) {
        
            
    if (features[2 / num_features][2 % num_features] <= 0.26769010722637177) {
        
            
    return 5;

        
    }
    else {
        
            
    return 0;

        
    }

        
    }
    else {
        
            
    return 5;

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    if (features[7 / num_features][7 % num_features] <= 0.5688254237174988) {
        
            
    if (features[17 / num_features][17 % num_features] <= 0.028815750032663345) {
        
            
    return 0;

        
    }
    else {
        
            
    return 4;

        
    }

        
    }
    else {
        
            
    return 5;

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    if (features[1 / num_features][1 % num_features] <= 0.37176355719566345) {
        
            
    if (features[25 / num_features][25 % num_features] <= 0.7851495146751404) {
        
            
    if (features[16 / num_features][16 % num_features] <= 0.6262001693248749) {
        
            
    if (features[24 / num_features][24 % num_features] <= 0.24253063648939133) {
        
            
    return 0;

        
    }
    else {
        
            
    return 5;

        
    }

        
    }
    else {
        
            
    return 0;

        
    }

        
    }
    else {
        
            
    return 5;

        
    }

        
    }
    else {
        
            
    if (features[19 / num_features][19 % num_features] <= 0.5232776701450348) {
        
            
    if (features[24 / num_features][24 % num_features] <= 0.16606169939041138) {
        
            
    if (features[16 / num_features][16 % num_features] <= 0.801967978477478) {
        
            
    return 4;

        
    }
    else {
        
            
    if (features[1 / num_features][1 % num_features] <= 0.49720780551433563) {
        
            
    if (features[12 / num_features][12 % num_features] <= 0.1834699511528015) {
        
            
    return 0;

        
    }
    else {
        
            
    return 4;

        
    }

        
    }
    else {
        
            
    return 5;

        
    }

        
    }

        
    }
    else {
        
            
    return 0;

        
    }

        
    }
    else {
        
            
    if (features[13 / num_features][13 % num_features] <= 0.032902538776397705) {
        
            
    return 0;

        
    }
    else {
        
            
    if (features[24 / num_features][24 % num_features] <= 0.10208217054605484) {
        
            
    return 4;

        
    }
    else {
        
            
    if (features[23 / num_features][23 % num_features] <= 0.49578920006752014) {
        
            
    if (features[11 / num_features][11 % num_features] <= 0.9049805700778961) {
        
            
    if (features[17 / num_features][17 % num_features] <= 0.031213424168527126) {
        
            
    if (features[3 / num_features][3 % num_features] <= 0.3532170504331589) {
        
            
    return 5;

        
    }
    else {
        
            
    return 4;

        
    }

        
    }
    else {
        
            
    if (features[9 / num_features][9 % num_features] <= 0.9043790400028229) {
        
            
    return 5;

        
    }
    else {
        
            
    if (features[11 / num_features][11 % num_features] <= 0.9044753015041351) {
        
            
    return 0;

        
    }
    else {
        
            
    return 5;

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    if (features[24 / num_features][24 % num_features] <= 0.23061352968215942) {
        
            
    if (features[18 / num_features][18 % num_features] <= 0.5149378925561905) {
        
            
    return 5;

        
    }
    else {
        
            
    return 0;

        
    }

        
    }
    else {
        
            
    return 5;

        
    }

        
    }

        
    }
    else {
        
            
    return 0;

        
    }

        
    }

        
    }

        
    }

        
    }

        
    }

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    if (features[16 / num_features][16 % num_features] <= 0.7709376215934753) {
        
            
    if (features[18 / num_features][18 % num_features] <= 0.5243671536445618) {
        
            
    return 4;

        
    }
    else {
        
            
    if (features[17 / num_features][17 % num_features] <= 0.19198458455502987) {
        
            
    return 0;

        
    }
    else {
        
            
    return 1;

        
    }

        
    }

        
    }
    else {
        
            
    if (features[1 / num_features][1 % num_features] <= 0.7867160737514496) {
        
            
    return 5;

        
    }
    else {
        
            
    return 0;

        
    }

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    if (features[25 / num_features][25 % num_features] <= 0.8624342978000641) {
        
            
    if (features[14 / num_features][14 % num_features] <= 0.34600846469402313) {
        
            
    if (features[3 / num_features][3 % num_features] <= 0.23407050222158432) {
        
            
    return 4;

        
    }
    else {
        
            
    return 0;

        
    }

        
    }
    else {
        
            
    if (features[0 / num_features][0 % num_features] <= 0.20849759876728058) {
        
            
    return 4;

        
    }
    else {
        
            
    if (features[19 / num_features][19 % num_features] <= 0.5873609781265259) {
        
            
    if (features[9 / num_features][9 % num_features] <= 0.8167393207550049) {
        
            
    return 0;

        
    }
    else {
        
            
    return 5;

        
    }

        
    }
    else {
        
            
    if (features[14 / num_features][14 % num_features] <= 0.5859457850456238) {
        
            
    return 0;

        
    }
    else {
        
            
    return 1;

        
    }

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    return 4;

        
    }

        
    }

        
    }

        
    }
    else {
        
            
    if (features[6 / num_features][6 % num_features] <= 0.25091229379177094) {
        
            
    if (features[20 / num_features][20 % num_features] <= 0.5579703450202942) {
        
            
    return 0;

        
    }
    else {
        
            
    return 1;

        
    }

        
    }
    else {
        
            
    if (features[3 / num_features][3 % num_features] <= 0.45077355206012726) {
        
            
    if (features[1 / num_features][1 % num_features] <= 0.3621310144662857) {
        
            
    return 0;

        
    }
    else {
        
            
    return 1;

        
    }

        
    }
    else {
        
            
    return 1;

        
    }

        
    }

        
    }

        
    }

        
    }

}



int predict() {
    
        step_1(step_0_output, step_1_output);
    
        step_2(step_1_output, step_2_output);
    
        return step_3(step_2_output);
    
}
#endif