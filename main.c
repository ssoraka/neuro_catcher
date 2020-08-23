#include "header.h"

double w_ij[N_HIDDEN * N_INPUT] = {0.926521, 0.757316, 0.154907, 0.115540, 0.309731, 0.335982, 0.126084, 0.678021, 0.998833, 0.902427, 0.028922, 0.177141, 0.897035, 0.500867, 0.899664, 0.085277, 0.721571, 0.886942, 0.313186, 0.589303, 0.038256, 0.355651, 0.602145, 0.701724, 0.792468, 0.382599, 0.657911, 0.817030, 0.717127, 0.580693, 0.587577, 0.643648, 0.338009, 0.742484, 0.759189, 0.647740, 0.078467, 0.885273, 0.325762, 0.077299, 0.787700, 0.354684, 0.254440, 0.684735, 0.855550, 0.154104, 0.770011, 0.577121, 0.041047, 0.083197, 0.166424, 0.079303, 0.438848, 0.768569, 0.781027, 0.231316, 0.151167, 0.438938, 0.048346, 0.868295, 0.019631, 0.635923, 0.511943, 0.357640, 0.378408, 0.271132, 0.005380, 0.456874, 0.156404, 0.331141, 0.534174, 0.944104, 0.685825, 0.788614, 0.628839, 0.541376, 0.942718, 0.398850, 0.118497, 0.983765, 0.482047, 0.284921, 0.063068, 0.920895, 0.053490, 0.844095, 0.152211, 0.204657, 0.283033, 0.200558, 0.072952, 0.302664, 0.836481, 0.584895, 0.660304, 0.214888, 0.856027, 0.665684, 0.671763, 0.012431, 0.996826, 0.205936, 0.956535, 0.682651, 0.994550, 0.585374, 0.224027, 0.937268, 0.984224, 0.342523, 0.921033, 0.466271, 0.627444, 0.984101, 0.387166, 0.680935, 0.828196, 0.539377, 0.885592, 0.111229, 0.739935, 0.958544, 0.413893, 0.576416, 0.543439, 0.074197, 0.791304, 0.399466, 0.739881, 0.463066, 0.411897, 0.736707, 0.669003, 0.368432, 0.419358, 0.663553, 0.953806, 0.643384, 0.600821, 0.938029, 0.985908, 0.521854, 0.404300, 0.613352, 0.505955, 0.791466, 0.294287, 0.334151, 0.330843, 0.179879, 0.445379, 0.070778, 0.138423, 0.859272, 0.647193, 0.681862, 0.933469, 0.438497, 0.081328, 0.673350, 0.901564, 0.493225, 0.410057, 0.570566, 0.861657, 0.829414, 0.234119, 0.815463, 0.472799, 0.834939, 0.753492, 0.458706, 0.356793, 0.157792, 0.072059, 0.862748, 0.949258, 0.366345, 0.196899, 0.280101, 0.546224, 0.642278, 0.350878, 0.684647, 0.501550, 0.998071, 0.366509, 0.435019, 0.436569, 0.447836, 0.108369, 0.338132, 0.941061, 0.518426, 0.908698, 0.802718, 0.347840, 0.142817, 0.618181, 0.820639, 0.977756, 0.371673, 0.279345, 0.334549, 0.529465, 0.351404, 0.197298, 0.478722, 0.717749, 0.394196, 0.758823, 0.263973, 0.036474, 0.109701, 0.948620, 0.538024, 0.107773, 0.315128, 0.973043, 0.544341, 0.762965, 0.081411, 0.882473, 0.704026, 0.599837, 0.791171, 0.506744, 0.947677, 0.933988, 0.124925, 0.768316, 0.911744, 0.496598, 0.047661, 0.246294, 0.026063, 0.399065, 0.443591, 0.504785, 0.116814, 0.837787, 0.263608, 0.380787, 0.874262, 0.373309, 0.329406, 0.412286, 0.481081, 0.644535, 0.385328, 0.025423, 0.407499, 0.466740, 0.907896, 0.111525, 0.066577, 0.699067, 0.618269, 0.014254, 0.633055, 0.743194, 0.782569, 0.544799, 0.239792, 0.830230, 0.791093, 0.265854, 0.229295, 0.234684, 0.770639, 0.346108, 0.072472, 0.034247, 0.726895, 0.946733, 0.407556, 0.056301, 0.359019, 0.888637, 0.700836, 0.744347, 0.914060, 0.108335, 0.211087, 0.821956, 0.219860, 0.277663, 0.521023, 0.838129, 0.291917, 0.154078, 0.581323, 0.074487, 0.698877, 0.821115, 0.904717, 0.489970, 0.086970, 0.134012, 0.724654, 0.857609, 0.480120, 0.797125, 0.891856, 0.207015, 0.743859, 0.299412, 0.263316, 0.102877, 0.188049, 0.964152, 0.847224, 0.102109, 0.072487, 0.058311, 0.924065, 0.292347, 0.335975, 0.445087, 0.130477, 0.627892, 0.599165, 0.711800, 0.702378, 0.298042, 0.532915, 0.607095, 0.788012, 0.619885, 0.741107, 0.512666, 0.477494, 0.221227, 0.309791, 0.369350, 0.428242, 0.053649, 0.668762, 0.691558, 0.156527, 0.856811, 0.655710, 0.003751, 0.958920, 0.728198, 0.062062, 0.882985, 0.020545, 0.398037, 0.328072, 0.151021, 0.025928, 0.927237, 0.862821, 0.728307, 0.225279, 0.395737, 0.335402, 0.013291, 0.015622, 0.076509, 0.525957, 0.493116, 0.297735, 0.835748, 0.862466, 0.725977, 0.889397, 0.531227, 0.417536, 0.045924, 0.388039, 0.073246, 0.049675, 0.346959, 0.801444, 0.111737, 0.229944, 0.821988, 0.509774, 0.558016, 0.973010, 0.535702, 0.485254, 0.835831, 0.264009, 0.710533, 0.231568, 0.599411, 0.723824, 0.247190, 0.675920, 0.249781, 0.740305, 0.973655, 0.085529, 0.602771, 0.699633, 0.974926, 0.133998, 0.117168, 0.020850, 0.522037, 0.190414, 0.070525, 0.868996, 0.991858, 0.182262, 0.098939, 0.813847, 0.692036, 0.656956, 0.786856, 0.227739, 0.142209, 0.622688, 0.491748, 0.852742, 0.854256, 0.091159, 0.576567, 0.101445, 0.767079, 0.826348, 0.841750, 0.740734, 0.911876, 0.444521, 0.440367, 0.886802, 0.578519, 0.557535, 0.907652, 0.100556, 0.747950, 0.978177, 0.969551, 0.739808, 0.160439, 0.068491, 0.553654, 0.852476, 0.725446, 0.340511, 0.080215, 0.867656, 0.963199, 0.571963, 0.720398, 0.817454, 0.663122, 0.296964, 0.918899, 0.430201, 0.123312, 0.760649, 0.170935, 0.035188, 0.205170, 0.611302, 0.921990, 0.783689, 0.168837, 0.829642, 0.884245, 0.916787, 0.807820, 0.853796, 0.656594, 0.968259, 0.922287, 0.210249, 0.820735, 0.647733, 0.550760, 0.900950, 0.515389, 0.513958, 0.472912, 0.235787, 0.331413, 0.136034, 0.532751, 0.250312, 0.566235, 0.656063, 0.010961, 0.737170, 0.691251, 0.216131, 0.348471, 0.613242, 0.999821, 0.517308, 0.442884, 0.884066, 0.434095, 0.250704, 0.737862, 0.090689, 0.218963, 0.660149, 0.300938, 0.039698, 0.307882, 0.851698, 0.940647, 0.823271, 0.365656, 0.413559, 0.059057, 0.697069, 0.549593, 0.591808, 0.947381, 0.115828, 0.247871, 0.958342, 0.852998, 0.939123, 0.174473, 0.201469, 0.552364, 0.174294, 0.718777, 0.995248, 0.058360, 0.152872, 0.245952, 0.796221, 0.243561, 0.464914, 0.456370, 0.544499, 0.504612, 0.764252, 0.396197, 0.445259, 0.587523, 0.761853, 0.858818, 0.646580, 0.458922, 0.408411, 0.238388, 0.406303, 0.524240, 0.486260, 0.364645, 0.377237, 0.425382, 0.539118, 0.578706, 0.977746, 0.713412, 0.297484, 0.972995, 0.771772, 0.450356, 0.218946, 0.567993, 0.693917, 0.683861, 0.024363, 0.238417, 0.188472, 0.788615, 0.634614, 0.633731, 0.376138, 0.396467, 0.492549, 0.022718, 0.855390, 0.900961, 0.261106, 0.261692, 0.425200, 0.747366, 0.626337, 0.802438, 0.172748, 0.165456, 0.381144, 0.150495, 0.878868, 0.678628, 0.123489, 0.650640, 0.128984, 0.342435, 0.218633, 0.822901, 0.026296, 0.242996, 0.061318, 0.214768, 0.031612, 0.695932, 0.848500, 0.407750, 0.092399, 0.341049, 0.430468, 0.947788, 0.242010, 0.691574, 0.209481, 0.667210, 0.438939, 0.835818, 0.469648, 0.611688, 0.001274, 0.850792, 0.762182, 0.880141, 0.529420, 0.885671, 0.530781, 0.658404, 0.228107, 0.749414, 0.481305, 0.254403, 0.992410, 0.542623, 0.469171, 0.024022, 0.238555, 0.317671, 0.431772, 0.330954, 0.658720, 0.862239, 0.278742, 0.900730, 0.553813, 0.488223, 0.567941, 0.992752, 0.324041, 0.037589, 0.604440, 0.325315, 0.888381, 0.366622, 0.205457, 0.417801, 0.252293, 0.736238, 0.076205, 0.480400, 0.485652, 0.557511, 0.734803, 0.478062, 0.100134, 0.203974, 0.502084, 0.338689, 0.521645, 0.933856, 0.669643, 0.180365, 0.796095, 0.948385, 0.081095, 0.349908, 0.436608, 0.649036, 0.342660, 0.760649, 0.686625, 0.947100, 0.085964, 0.575005, 0.313722, 0.291421, 0.992807, 0.566015, 0.027659, 0.069012, 0.046416, 0.513310, 0.626522, 0.781218, 0.991372, 0.726656, 0.985192, 0.493456, 0.065345, 0.506837, 0.427311, 0.734988, 0.687202, 0.223406, 0.683372, 0.768297, 0.573314, 0.119980, 0.417333, 0.915974, 0.880629, 0.103958, 0.863073, 0.966594, 0.678963, 0.176795, 0.258015, 0.671770, 0.742811, 0.285673, 0.740782, 0.789226, 0.798983, 0.367304, 0.570445, 0.790355, 0.093961, 0.555637, 0.283811, 0.159306, 0.062474, 0.711123, 0.894293, 0.749676, 0.934529, 0.577666, 0.517974, 0.507843, 0.697646, 0.935307, 0.423816, 0.578275, 0.039265, 0.286890, 0.544869, 0.718228, 0.463685, 0.802883, 0.389998, 0.206496, 0.088556, 0.130780, 0.995722, 0.887539, 0.498084, 0.566167, 0.677895, 0.592045, 0.121804, 0.961706, 0.751350, 0.184278, 0.672829, 0.645644, 0.933954, 0.607358, 0.223309, 0.451928, 0.115200, 0.920955, 0.387236, 0.539016, 0.499230, 0.426501, 0.825906, 0.044099, 0.144729, 0.289591, 0.846982, 0.534727, 0.496087, 0.935538, 0.665507, 0.491809, 0.823078, 0.163592, 0.057975, 0.500972, 0.755636, 0.179779, 0.462678, 0.506987, 0.364057, 0.135507, 0.152630, 0.298012, 0.742865, 0.375939, 0.749940, 0.858065, 0.296894, 0.137176, 0.397081, 0.796124, 0.563676, 0.222987, 0.840223, 0.708405, 0.512578, 0.687205, 0.243133, 0.008664, 0.622743, 0.908640, 0.500473, 0.445820, 0.072232, 0.558448, 0.946793, 0.827868, 0.738228, 0.409471, 0.334854, 0.102285, 0.544978, 0.487485, 0.400296, 0.287843, 0.863424, 0.150236, 0.145908, 0.160318, 0.287412, 0.542989, 0.956443, 0.851088, 0.765976, 0.796666, 0.559494, 0.278554, 0.483871, 0.802626, 0.287218, 0.106614, 0.711266, 0.787690, 0.552434, 0.783498, 0.346139, 0.499227, 0.611366, 0.084366, 0.908698, 0.946220, 0.186651, 0.453676, 0.433705, 0.586947, 0.741520, 0.297129, 0.737184, 0.887428, 0.457448, 0.024596, 0.430417, 0.413891, 0.875684, 0.196393, 0.210556, 0.435178, 0.474946, 0.694427, 0.237804, 0.762164, 0.801040, 0.949070, 0.549855, 0.353474, 0.732569, 0.895993, 0.852701, 0.343935, 0.980360, 0.761399, 0.290155, 0.167011, 0.215076, 0.723860, 0.753958, 0.956595, 0.020989, 0.491142, 0.844023, 0.478437, 0.515738, 0.274440, 0.892328, 0.391422, 0.470832, 0.102884, 0.826599, 0.945779, 0.797311, 0.064403, 0.707943, 0.598351, 0.013474};
double w_oi[DIR_COUNT * N_HIDDEN] = {0.253628, 0.777493, 0.218871, 0.317023, 0.896418, 0.234020, 0.411757, 0.534720, 0.636261, 0.645258, 0.259868, 0.054791, 0.927129, 0.588587, 0.280757, 0.816335, 0.485192, 0.283052, 0.010268, 0.954138, 0.507779, 0.357657, 0.599622, 0.091821, 0.621450, 0.019634, 0.985545, 0.347227, 0.867790, 0.361272, 0.764189, 0.121418, 0.138765, 0.983059, 0.438441, 0.035183, 0.217079, 0.850197, 0.569904, 0.853340, 0.495455, 0.829771, 0.908131, 0.422585, 0.418358, 0.188888, 0.238919, 0.903551, 0.471940, 0.249187, 0.857689, 0.979718, 0.606843, 0.457311, 0.071540, 0.228294, 0.476945, 0.057085, 0.575521, 0.344734, 0.418357, 0.339710, 0.466152, 0.557122, 0.322769, 0.904593, 0.592306, 0.539848, 0.754790, 0.162209, 0.393188, 0.250245, 0.991981, 0.301319, 0.672830, 0.410339, 0.490207, 0.911749, 0.313890, 0.962147, 0.160936, 0.171579, 0.941865, 0.767779, 0.628889, 0.013405, 0.996073, 0.105834, 0.070490, 0.571594};

void init_test_weight(t_layer *layer, double *w) {
	int i = 0;
	while ( i < layer->i_n) {
		int j = 0;
		while ( j < layer->j_n) {
			layer->w_ij[i][j] = w[i * N_INPUT + j];
			j++;
		}
		i++;
	}
}

int main() {
	printf("Hello, World!\n");

	t_game game;
	t_brain brain;
	t_layer layer[2];

	init_brain(&brain, layer, 2);
	init_layer(layer, N_HIDDEN, N_INPUT, SIMPLE);
	init_test_weight(layer, w_ij);
	init_layer(layer + 1, DIR_COUNT, N_HIDDEN, SOFTMAX);
	init_test_weight(layer + 1, w_oi);

	game = init_game(&brain);

	set_input(&brain, game.input);
	set_output(&brain, game.output);

	/*
	// не заработало нифига
	int example;
	int ep;

	ep = 0;
	while (ep < 1000) {
		//проиграли игру, получили историю
		run_one_game(&game, FALSE);
		//определили награду
		game.reward = get_reward(&game);
		//теперь для каждого случая истории оучаем
		example = 0;
		while (example < MAP_H) {
			//восстанавливаем
			set_pos_on_map_from_store(&game, example);
			calculate_brain(&brain);
			teaching_brain(&brain);

			clear_map_from_store(&game, example);
			example++;
		}
		ep++;
	}*/


	printf("first\n");
	int points[2] = {0,0};
	int ep;

	ep = 0;
	while (ep < 50000) {
		run_one_game(&game, FALSE);
		game.reward = get_reward(&game);
		if (game.reward == 1) {
			points[0]++;
		} else {
			points[1]++;
		}
		printf("+ %d_ - %d | %lf\n", points[0], points[1], ((double)points[0]) / (points[1] + points[0]));
		int example = 0;
		while (example < STORE) {
			//восстанавливаем
			set_pos_on_map_from_store(&game, example);
			calculate_brain(&brain);

			teaching_brain(&brain);

			clear_map_from_store(&game, example);
			example++;
		}
		game.gamer_pos = N_INPUT - MAP_W / 2 - 1;
		ep++;
	}
	run_one_game(&game, TRUE);
	game.gamer_pos = N_INPUT - MAP_W / 2 - 1;
	run_one_game(&game, TRUE);
	game.gamer_pos = N_INPUT - MAP_W / 2 - 1;
	run_one_game(&game, TRUE);
	//print_layer_weight(layer + 1);
	print_arr_double(layer[1].f, 3);
	return 0;
}
