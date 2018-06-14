#include "../include/pCT_development.h"
//	#include <getopt.h>
//	#include <unistd.h>
//typedef std::tuple<configurations, std::string, PARAM_TYPES> PCT_PARAMS;
////typedef std::tuple<class, std::string, PARAM_TYPES> PCT_PARAMS;
////template<typename T> typedef std::tuple<T, std::string, PARAM_TYPES> PCT_PARAMS;
////extern PCT_PARAMS pct_params;
//std::vector<PCT_PARAMS> pct_params;
////PCT_PARAMS pct_params;
//std::vector<PCT_PARAMS> pct_params_vec;

//typedef std::tuple<configurations, std::string, PARAM_TYPES> PCT_PARAMS;
//extern std::vector<PCT_PARAMS> pct_params;
//std::vector<PCT_PARAMS> pct_params;
//std::vector<PCT_PARAMS> pct_params_vec;

struct option long_options[] =
{
    {"rand_engine", required_argument, NULL, 1},
    {"tvs_rand_engine", required_argument, NULL, 2},
    {"scan_type", required_argument, NULL, 3},
    {"file_type", required_argument, NULL, 4},
    {"data_format", required_argument, NULL, 5},
    {"image_basis", required_argument, NULL, 6},
    {"fbp_filter", required_argument, NULL, 7},
    {"endpoints_hull", required_argument, NULL, 8},
    {"x_0", required_argument, NULL, 9},
    {"endpoints_alg", required_argument, NULL, 10},
    {"endpoints_tx_mode", required_argument, NULL, 11},
    {"mlp_algorithm", required_argument, NULL, 12},
    {"projection_algorithm", required_argument, NULL, 13},
    {"recon_tx_mode", required_argument, NULL, 14},
    {"drop_tx_mode", required_argument, NULL, 15},
    {"s_curve", required_argument, NULL, 16},
    {"robust_method", required_argument, NULL, 17},
    {"run_on", required_argument, NULL, 18},
    {"testing_on", required_argument, NULL, 19},
    {"block_testing_on", required_argument, NULL, 20},
    {"s_curve_testing_on", required_argument, NULL, 21},
    {"ntvs_testing_on", required_argument, NULL, 22},
    {"overwriting_ok", required_argument, NULL, 23},
    {"exit_after_binning", required_argument, NULL, 24},
    {"exit_after_hulls", required_argument, NULL, 25},
    {"exit_after_cuts", required_argument, NULL, 26},
    {"exit_after_sinogram", required_argument, NULL, 27},
    {"exit_after_fbp", required_argument, NULL, 28},
    {"close_after_execution", required_argument, NULL, 29},
    {"debug_text_on", required_argument, NULL, 30},
    {"sample_std_dev", required_argument, NULL, 31},
    {"fbp_on", required_argument, NULL, 32},
    {"import_filtered_fbp", required_argument, NULL, 33},
    {"sc_on", required_argument, NULL, 34},
    {"msc_on", required_argument, NULL, 35},
    {"sm_on", required_argument, NULL, 36},
    {"count_0_wepls", required_argument, NULL, 37},
    {"direct_image_reconstruction", required_argument, NULL, 38},
    {"mlp_file_exists", required_argument, NULL, 39},
    {"mlp_endpoints_file_exists", required_argument, NULL, 40},
    {"input_directory", required_argument, NULL, 41},
    {"output_directory", required_argument, NULL, 42},
    {"input_folder", required_argument, NULL, 43},
    {"output_folder", required_argument, NULL, 44},
    {"binary_encoding", required_argument, NULL, 45},
    {"single_data_file", required_argument, NULL, 46},
    {"ssd_in_mm", required_argument, NULL, 47},
    {"data_in_mm", required_argument, NULL, 48},
    {"micah_sim", required_argument, NULL, 49},
    {"write_bin_wepls", required_argument, NULL, 50},
    {"write_wepl_dists", required_argument, NULL, 51},
    {"write_ssd_angles", required_argument, NULL, 52},
    {"write_sc_hull", required_argument, NULL, 53},
    {"write_msc_counts", required_argument, NULL, 54},
    {"write_msc_hull", required_argument, NULL, 55},
    {"write_sm_counts", required_argument, NULL, 56},
    {"write_sm_hull", required_argument, NULL, 57},
    {"write_fbp_image", required_argument, NULL, 58},
    {"write_fbp_hull", required_argument, NULL, 59},
    {"write_avg_fbp", required_argument, NULL, 60},
    {"write_median_fbp", required_argument, NULL, 61},
    {"write_filtered_hull", required_argument, NULL, 62},
    {"write_x_hull", required_argument, NULL, 63},
    {"write_x_0", required_argument, NULL, 64},
    {"write_x_ki", required_argument, NULL, 65},
    {"write_x", required_argument, NULL, 66},
    {"drop_block_size", required_argument, NULL, 67},
    {"threads_per_block", required_argument, NULL, 68},
    {"endpoints_per_block", required_argument, NULL, 69},
    {"histories_per_block", required_argument, NULL, 70},
    {"endpoints_per_thread", required_argument, NULL, 71},
    {"histories_per_thread", required_argument, NULL, 72},
    {"voxels_per_thread", required_argument, NULL, 73},
    {"max_gpu_histories", required_argument, NULL, 74},
    {"max_cuts_histories", required_argument, NULL, 75},
    {"max_endpoints_histories", required_argument, NULL, 76},
    {"max_intersections", required_argument, NULL, 77},
    {"gantry_angle_interval", required_argument, NULL, 78},
    {"num_scans", required_argument, NULL, 79},
    {"ssd_t_size", required_argument, NULL, 80},
    {"ssd_v_size", required_argument, NULL, 81},
    {"t_shift", required_argument, NULL, 82},
    {"u_shift", required_argument, NULL, 83},
    {"v_shift", required_argument, NULL, 84},
    {"t_bin_size", required_argument, NULL, 85},
    {"v_bin_size", required_argument, NULL, 86},
    {"angular_bin_size", required_argument, NULL, 87},
    {"sigmas_to_keep", required_argument, NULL, 88},
    {"fbp_threshold", required_argument, NULL, 89},
    {"recon_cyl_radius", required_argument, NULL, 90},
    {"slice_thickness", required_argument, NULL, 91},
    {"voxel_width", required_argument, NULL, 92},
    {"voxel_height", required_argument, NULL, 93},
    {"voxel_thickness", required_argument, NULL, 94},
    {"sc_lower_threshold", required_argument, NULL, 95},
    {"sc_upper_threshold", required_argument, NULL, 96},
    {"msc_upper_threshold", required_argument, NULL, 97},
    {"msc_lower_threshold", required_argument, NULL, 98},
    {"msc_diff_thresh", required_argument, NULL, 99},
    {"sm_lower_threshold", required_argument, NULL, 100},
    {"sm_upper_threshold", required_argument, NULL, 101},
    {"sm_scale_threshold", required_argument, NULL, 102},
    {"voxel_step_size", required_argument, NULL, 103},
    {"prime_offset", required_argument, NULL, 104},
    {"eta", required_argument, NULL, 105},
    {"method", required_argument, NULL, 106},
    {"psi_sign", required_argument, NULL, 107},
    {"lambda", required_argument, NULL, 108},
    {"iterations", required_argument, NULL, 109},
    {"ignore_short_mlp", required_argument, NULL, 110},
    {"min_mlp_length", required_argument, NULL, 111},
    {"bound_image", required_argument, NULL, 112},
    {"s_curve_on", required_argument, NULL, 113},
    {"sigmoid_steepness", required_argument, NULL, 114},
    {"sigmoid_mid_shift", required_argument, NULL, 115},
    {"dual_sided_s_curve", required_argument, NULL, 116},
    {"tvs_on", required_argument, NULL, 117},
    {"tvs_first", required_argument, NULL, 118},
    {"tvs_parallel", required_argument, NULL, 119},
    {"tvs_conditioned", required_argument, NULL, 120},
    {"tvs_min_beta", required_argument, NULL, 121},
    {"tv_threshold", required_argument, NULL, 122},
    {"alpha", required_argument, NULL, 123},
    {"ell_0", required_argument, NULL, 124},
    {"ell", required_argument, NULL, 125},
    {"beta_0", required_argument, NULL, 126},
    {"beta", required_argument, NULL, 127},
    {"n", required_argument, NULL, 128},
    {"avg_filter_fbp", required_argument, NULL, 129},
    {"avg_filter_hull", required_argument, NULL, 130},
    {"avg_filter_x_0", required_argument, NULL, 131},
    {"median_filter_fbp", required_argument, NULL, 132},
    {"median_filter_hull", required_argument, NULL, 133},
    {"median_filter_x_0", required_argument, NULL, 134},
    {"hull_avg_filter_radius", required_argument, NULL, 135},
    {"fbp_avg_filter_radius", required_argument, NULL, 136},
    {"x_0_avg_filter_radius", required_argument, NULL, 137},
    {"fbp_med_filter_radius", required_argument, NULL, 138},
    {"hull_med_filter_radius", required_argument, NULL, 139},
    {"x_0_med_filter_radius", required_argument, NULL, 140},
    {"hull_avg_filter_threshold", required_argument, NULL, 141},
    {"fbp_avg_filter_threshold", required_argument, NULL, 142},
    {"x_0_avg_filter_threshold", required_argument, NULL, 143},
    {"tested_by_string", required_argument, NULL, 144},
    {"code_owner", required_argument, NULL, 145},
    {"program_version", required_argument, NULL, 146},
    {"section_exit_string", required_argument, NULL, 147},
    {"my_recon_dir", required_argument, NULL, 148},
    {"current_git_branch", required_argument, NULL, 149},
    {"tardis_rcode_dir", required_argument, NULL, 150},
    {"perturb_A", required_argument, NULL, 151},
    {"perturbation_parameter", required_argument, NULL, 152},
    {"max_histories_2_remove", required_argument, NULL, 153},
    {"source_radius", required_argument, NULL, 154},
    {"trig_table_step", required_argument, NULL, 155},
    {"run_on_kodiak", required_argument, NULL, 156},
    {"lambda_k_type", required_argument, NULL, 157},
    {"lambda_0", required_argument, NULL, 158},
	{"lambda_m", required_argument, NULL, 159},
    {"alpha_x0", required_argument, NULL, 160},
    {"ell_0_x0", required_argument, NULL, 161},
    {"n_x0", required_argument, NULL, 162},
    {"superiorize_x_0", required_argument, NULL, 163},
    {"sabip_config", required_argument, NULL, 164},
    {"sadrop_strings", required_argument, NULL, 165},
    {"sadrop_blocks_per_string", required_argument, NULL, 166},
    //{"sadrop_string_blocks", required_argument, NULL, 166},
	{"block_ordering", required_argument, NULL, 167},
    /*{"workstation_1_hostname", required_argument, NULL, 172},
    {"workstation_2_hostname", required_argument, NULL, 173},
    {"kodiak_hostname", required_argument, NULL, 174},
    {"whartnell_hostname", required_argument, NULL, 175},
    {"whartnell_ID", required_argument, NULL, 176},
    {"jpertwee_ID", required_argument, NULL, 177},
    {"jpertwee_hostname", required_argument, NULL, 178},
    {"bash_secure_copy", required_argument, NULL, 179},
    {"bash_copy_dir", required_argument, NULL, 180},
    {"bash_copy_file", required_argument, NULL, 181},
    {"baylor_username", required_argument, NULL, 182},
    {"cluster_username", required_argument, NULL, 183},
    {"kodiak_login", required_argument, NULL, 184},
    {"whartnell_login", required_argument, NULL, 185},
    {"ptroughton_login", required_argument, NULL, 186},
    {"jpertwee_login", required_argument, NULL, 187},
    {"tbaker_login", required_argument, NULL, 188},
    {"pdavison_login", required_argument, NULL, 189},
    {"pct_path_global", required_argument, NULL, 190},
    {"pct_path_tardis", required_argument, NULL, 191},
    {"pct_data_dir", required_argument, NULL, 192},
    {"pct_code_dir", required_argument, NULL, 193},
    {"pct_recon_dir", required_argument, NULL, 194},
    {"pct_recon_path", required_argument, NULL, 195},
    {"my_data_dir", required_argument, NULL, 196},
    {"my_recon_dir", required_argument, NULL, 197},
    {"my_code_dir", required_argument, NULL, 198},
    {"ws2_code_dir", required_argument, NULL, 199},
    {"ws2_recon_dir", required_argument, NULL, 200},
    {"jpertwee_code_dir", required_argument, NULL, 201},
    {"jpertwee_recon_dir", required_argument, NULL, 202},
    {"whartnell_code_dir", required_argument, NULL, 203},
    {"whartnell_recon_dir", required_argument, NULL, 204},
    {"pct_data_folder", required_argument, NULL, 205},
    {"pct_code_folder", required_argument, NULL, 206},
    {"raw_data_folder", required_argument, NULL, 207},
    {"processed_data_folder", required_argument, NULL, 208},
    {"projection_data_folder", required_argument, NULL, 209},
    {"recon_data_folder", required_argument, NULL, 210},
    {"organized_data_folder", required_argument, NULL, 211},
    {"experimental_folder", required_argument, NULL, 212},
    {"simulated_folder", required_argument, NULL, 213},
    {"geant4_dir_prefix", required_argument, NULL, 214},
    {"topas_dir_prefix", required_argument, NULL, 215},
    {"raw_links_folder", required_argument, NULL, 216},
    {"projection_links_folder", required_argument, NULL, 217},
    {"reconstruction_folder", required_argument, NULL, 218},
    {"hostname_cmd", required_argument, NULL, 219},
    {"username_cmd", required_argument, NULL, 220},
    {"userid_cmd", required_argument, NULL, 221},
    {"groupname_cmd", required_argument, NULL, 222},
    {"groupid_cmd", required_argument, NULL, 223},
    {"groupnames_cmd", required_argument, NULL, 224},
    {"groupids_cmd", required_argument, NULL, 225},
    {"hostname_envvar", required_argument, NULL, 226},
    {"home_dir_envvar", required_argument, NULL, 227},
    {"username_envvar", required_argument, NULL, 228},
    {"userid_envvar", required_argument, NULL, 229},
    {"userid_effect_envvar", required_argument, NULL, 230},
    {"groups_envvar", required_argument, NULL, 231},
    {"ostype_envvar", required_argument, NULL, 232},
    {"path_envvar", required_argument, NULL, 233},
    {"work_dir_envvar", required_argument, NULL, 234},
    {"owner_access", required_argument, NULL, 235},
    {"group_access", required_argument, NULL, 236},
    {"global_access", required_argument, NULL, 237},
    {"input_base_name", required_argument, NULL, 238},
    {"file_extension", required_argument, NULL, 239},
    {"config_filename", required_argument, NULL, 240},
    {"config_out_filename", required_argument, NULL, 241},
    {"log_filename", required_argument, NULL, 242},
    {"stdout_filename", required_argument, NULL, 243},
    {"stdin_filename", required_argument, NULL, 244},
    {"stderr_filename", required_argument, NULL, 245},
    {"execution_times_fname", required_argument, NULL, 246},
    {"sin_table_fname", required_argument, NULL, 247},
    {"cos_table_fname", required_argument, NULL, 248},
    {"coefficient_fname", required_argument, NULL, 249},
    {"poly_1_2_fname", required_argument, NULL, 250},
    {"poly_2_3_fname", required_argument, NULL, 251},
    {"poly_3_4_fname", required_argument, NULL, 252},
    {"poly_2_6_fname", required_argument, NULL, 253},
    {"poly_3_12_fname", required_argument, NULL, 254},
    {"sc_hull_fname", required_argument, NULL, 255},
    {"msc_hull_fname", required_argument, NULL, 256},
    {"sm_hull_fname", required_argument, NULL, 257},
    {"fbp_hull_fname", required_argument, NULL, 258},
    {"sm_counts_fname", required_argument, NULL, 259},
    {"msc_counts_fname", required_argument, NULL, 260},
    {"hull_fname", required_argument, NULL, 261},
    {"hull_avg_filter_fname", required_argument, NULL, 262},
    {"hull_med_filter_fname", required_argument, NULL, 263},
    {"input_hull_fname", required_argument, NULL, 264},
    {"sinogram_fname", required_argument, NULL, 265},
    {"sinogram_pre_fname", required_argument, NULL, 266},
    {"fbp_fname", required_argument, NULL, 267},
    {"fbp_after_fname", required_argument, NULL, 268},
    {"fbp_image_filter_fname", required_argument, NULL, 269},
    {"fbp_med_filter_fname", required_argument, NULL, 270},
    {"fbp_avg_filter_filename", required_argument, NULL, 271},
    {"input_iterate_fname", required_argument, NULL, 272},
    {"import_fbp_fname", required_argument, NULL, 273},
    {"x_0_fname", required_argument, NULL, 274},
    {"x_fname", required_argument, NULL, 275},
    {"bin_counts_pre_fname", required_argument, NULL, 276},
    {"bin_counts_fname", required_argument, NULL, 277},
    {"bin_counts_post_fname", required_argument, NULL, 278},
    {"mean_wepl_fname", required_argument, NULL, 279},
    {"mean_rel_ut_fname", required_argument, NULL, 280},
    {"mean_rel_uv_fname", required_argument, NULL, 281},
    {"stddev_rel_ut_fname", required_argument, NULL, 282},
    {"stddev_rel_uv_fname", required_argument, NULL, 283},
    {"stddev_wepl_fname", required_argument, NULL, 284},
    {"mlp_paths_fname", required_argument, NULL, 285},
    {"mlp_paths_error_fname", required_argument, NULL, 286},
    {"mlp_endpoints_fname", required_argument, NULL, 287},
    {"old_format_string", required_argument, NULL, 288},
    {"version_0_string", required_argument, NULL, 289},
    {"version_1_string", required_argument, NULL, 290},
    {"experimental_string", required_argument, NULL, 291},
    {"simulated_g_string", required_argument, NULL, 292},
    {"simulated_t_string", required_argument, NULL, 293},
    {"text_string", required_argument, NULL, 294},
    {"binary_string", required_argument, NULL, 295},
    {"default_rand_string", required_argument, NULL, 296},
    {"minstd_rand_string", required_argument, NULL, 297},
    {"minstd_rand0_string", required_argument, NULL, 298},
    {"mt19937_string", required_argument, NULL, 299},
    {"mt19937_64_string", required_argument, NULL, 300},
    {"randlux24_string", required_argument, NULL, 301},
    {"randlux48_string", required_argument, NULL, 302},
    {"knuth_b_string", required_argument, NULL, 303},
    {"voxels_string", required_argument, NULL, 304},
    {"blobs_string", required_argument, NULL, 305},
    {"means_string", required_argument, NULL, 306},
    {"counts_string", required_argument, NULL, 307},
    {"members_string", required_argument, NULL, 308},
    {"all_bins_string", required_argument, NULL, 309},
    {"specific_bins_string", required_argument, NULL, 310},
    {"by_bin_string", required_argument, NULL, 311},
    {"by_history_string", required_argument, NULL, 312},
    {"wepls_string", required_argument, NULL, 313},
    {"angles_string", required_argument, NULL, 314},
    {"positions_string", required_argument, NULL, 315},
    {"bin_nums_string", required_argument, NULL, 316},
    {"ram_lak_string", required_argument, NULL, 317},
    {"shepp_logan_string", required_argument, NULL, 318},
    {"none_string", required_argument, NULL, 319},
    {"sc_hull_string", required_argument, NULL, 320},
    {"msc_hull_string", required_argument, NULL, 321},
    {"sm_hull_string", required_argument, NULL, 322},
    {"fbp_hull_string", required_argument, NULL, 323},
    {"x_hull_string", required_argument, NULL, 324},
    {"hull_string", required_argument, NULL, 325},
    {"fbp_image_string", required_argument, NULL, 326},
    {"hybrid_string", required_argument, NULL, 327},
    {"zeros_string", required_argument, NULL, 328},
    {"import_string", required_argument, NULL, 329},
    {"full_tx_string", required_argument, NULL, 330},
    {"partial_tx_string", required_argument, NULL, 331},
    {"partial_tx_preallocated_string", required_argument, NULL, 332},
    {"bool_string", required_argument, NULL, 333},
    {"yes_bool_string", required_argument, NULL, 334},
    {"no_bool_string", required_argument, NULL, 335},
    {"standard_string", required_argument, NULL, 336},
    {"tabulated_string", required_argument, NULL, 337},
    {"art_string", required_argument, NULL, 338},
    {"sart_string", required_argument, NULL, 339},
    {"drop_string", required_argument, NULL, 340},
    {"bip_string", required_argument, NULL, 341},
    {"sap_string", required_argument, NULL, 342},
    {"robusta_string", required_argument, NULL, 343},
    {"robustb_string", required_argument, NULL, 344},
    {"sigmoid_string", required_argument, NULL, 345},
    {"tanh_string", required_argument, NULL, 346},
    {"atan_string", required_argument, NULL, 347},
    {"erf_string", required_argument, NULL, 348},
    {"lin_over_root_string", required_argument, NULL, 349},
    {"ols_string", required_argument, NULL, 350},
    {"tls_string", required_argument, NULL, 351},
    {"tikhonov_string", required_argument, NULL, 352},
    {"ridge_string", required_argument, NULL, 353},
    {"minmin_string", required_argument, NULL, 354},
    {"minmax_string", required_argument, NULL, 355},
    {"square_string", required_argument, NULL, 356},
    {"disk_string", required_argument, NULL, 357},
    {"erosion_string", required_argument, NULL, 358},
    {"dilation_string", required_argument, NULL, 359},
    {"opening_string", required_argument, NULL, 360},
    {"closing_string", required_argument, NULL, 361},
    {"object_l_string", required_argument, NULL, 362},
    {"scan_type_l_string", required_argument, NULL, 363},
    {"run_date_l_string", required_argument, NULL, 364},
    {"run_number_l_string", required_argument, NULL, 365},
    {"max_iterations", required_argument, NULL, 366},
    {"e_0", required_argument, NULL, 367},
    {"x0", required_argument, NULL, 368},
    {"rsp_air", required_argument, NULL, 369},
    {"beam_energy", required_argument, NULL, 370},
    {"source_radius", required_argument, NULL, 371},
    {"a_0", required_argument, NULL, 372},
    {"a_1", required_argument, NULL, 373},
    {"a_2", required_argument, NULL, 374},
    {"a_3", required_argument, NULL, 375},
    {"a_4", required_argument, NULL, 376},
    {"a_5", required_argument, NULL, 377},*/
    {NULL, 0, NULL, 0}
};

struct configurations
{

	RAND_GENERATORS		rand_engine;					// Specify the random number generator engine to use
	RAND_GENERATORS		tvs_rand_engine;					// Specify the random number generator engine to use
	SCAN_TYPES		scan_type;			  		// Specifies which of the defined filters will be used in FBP
	FILE_TYPES		file_type;						// Experimental or simulated data
	DATA_FORMATS		data_format;					// Specify which data format to use for this run
	IMAGE_BASES		image_basis;						// Specifies which basis is used to construct the images
	FILTER_TYPES		fbp_filter;			  		// Specifies which of the defined filters will be used in FBP
	HULL_TYPES		endpoints_hull;						// Specify which of the HULL_TYPES to use in this run's MLP calculations
	INITIAL_ITERATE		x_0;						// Specify which of the HULL_TYPES to use in this run's MLP calculations
	ENDPOINTS_ALGORITHMS	endpoints_alg;						// Specifies if boolean array is used to store whether a proton hit/missed the hull (BOOL) or uses the 1st MLP voxel (NO_BOOL)
	TX_OPTIONS		endpoints_tx_mode;		// Specifies GPU data tx mode for MLP endpoints as all data (FULL_TX), portions of data (PARTIAL_TX), or portions of data w/ reused GPU arrays (PARTIAL_TX_PREALLOCATED)
	LAMBDA_K_TYPES		lambda_k_type;					// Specifies whether the value of the relaxation parameter lambda is constant (CONSTANT) or linear (LINEAR_K) as a function of iteration k
	SABIP_CONFIGS		sabip_config;					// Specifies if # of BIP blocks per SAP string is explicitly set directly (SABIP_STRING_BLOCKS) or calculated based on # histories/SAP strings (SABIP_STRINGS)
	BLOCK_ORDERING		block_ordering;					// Specifies selected option for setting the order in which BIP blocks are being used in reconstruction
	MLP_ALGORITHMS		mlp_algorithm;					// Specifies whether calculations are performed explicitly (STANDARD) or if lookup tables are used for MLP calculations (TABULATED)
	PROJECTION_ALGORITHMS	projection_algorithm;							// Specify which of the projection algorithms to use for image reconstruction
	TX_OPTIONS		recon_tx_mode;						// Specifies GPU data tx mode for MLP+DROP as all data (FULL_TX), portions of data (PARTIAL_TX), or portions of data w/ reused GPU arrays (PARTIAL_TX_PREALLOCATED)
	TX_OPTIONS		drop_tx_mode;						// Specifies GPU data tx mode for MLP+DROP as all data (FULL_TX), portions of data (PARTIAL_TX), or portions of data w/ reused GPU arrays (PARTIAL_TX_PREALLOCATED)
	S_CURVES		s_curve;						// Specify S-curve to use to scale updates applied to voxels around the object boundary
	ROBUST_METHODS		robust_method;
	bool run_on;										// turn preprocessing on/off (t/f) to enter individual function testing without commenting
	bool testing_on;									// write output to "testing" directory (t) or to organized dat directory (f)
	bool block_testing_on;									// use value of variables relevant to block testing to name output directory (t) or not (f)
	bool s_curve_testing_on;									// use value of variables relevant to block testing to name output directory (t) or not (f)
	bool ntvs_testing_on;										// use value of variables relevant to block testing to name output directory (t) or not (f)
	bool overwriting_ok;									// allow output to
	bool exit_after_binning;									// exit program early after completing data read and initial processing
	bool exit_after_hulls;									// exit program early after completing hull-detection
	bool exit_after_cuts;									// exit program early after completing statistical cuts
	bool exit_after_sinogram;									// exit program early after completing the construction of the sinogram
	bool exit_after_fbp;									// exit program early after completing fbp
	bool close_after_execution;
	bool debug_text_on;										// provide (t) or suppress (f) print statements to console during execution
	bool sample_std_dev;										// use sample/population standard deviation (t/f) in statistical cuts (i.e. divisor is n/n-1)
	bool fbp_on;										// turn fbp on (t) or off (f)
	bool import_filtered_fbp;
	bool sc_on;									// turn space carving on (t) or off (f)
	bool msc_on;										// turn modified space carving on (t) or off (f)
	bool sm_on;									// turn space modeling on (t) or off (f)
	bool count_0_wepls;									// count the number of histories with wepl = 0 (t) or not (f)
	bool direct_image_reconstruction;
	bool mlp_file_exists;
	bool mlp_endpoints_file_exists;
	char input_directory[100];//   	= "//home//karbasip//";
	char output_directory[100];//  	= "//home//karbasip//";
	char input_folder[100];//	 	= "input_CTP404_4M";
	char output_folder[100];//     	= "cuda_test";
	bool binary_encoding;									// input data provided in binary (t) encoded files or asci text files (f)
	bool single_data_file;									// individual file for each gantry angle (t) or single data file for all data (f)
	bool ssd_in_mm;									// ssd distances from rotation axis given in mm (t) or cm (f)
	bool data_in_mm;									// input data given in mm (t) or cm (f)
	bool micah_sim;
	bool write_bin_wepls;									// write wepls for each bin to disk (t) for wepl distribution analysis, or do not (f)
	bool write_wepl_dists;									// write mean wepl values to disk (t) or not (f): t bin = columns, v bin = rows, 1 angle per file
	bool write_ssd_angles;									// write angles for each proton through entry/exit tracker planes to disk (t), or do not (f)
	bool write_sc_hull;									// write sc hull to disk (t) or not (f)
	bool write_msc_counts;								// write msc counts array to disk (t) or not (f) before performing edge detection
	bool write_msc_hull;								// write msc hull to disk (t) or not (f)
	bool write_sm_counts;									// write sm counts array to disk (t) or not (f) before performing edge detection
	bool write_sm_hull;									// write sm hull to disk (t) or not (f)
	bool write_fbp_image;									// write fbp image before thresholding to disk (t) or not (f)
	bool write_fbp_hull;									// write fbp hull to disk (t) or not (f)
	bool write_avg_fbp;									// write average filtered fbp image before thresholding to disk (t) or not (f)
	bool write_median_fbp;									// write median filtered fbp image to disk (t) or not (f)
	bool write_filtered_hull;									// write average filtered fbp image to disk (t) or not (f)
	bool write_x_hull;									// write the hull selected to be used in mlp calculations to disk (t) or not (f)
	bool write_x_0;									// write the hull selected to be used in mlp calculations to disk (t) or not (f)
	bool write_x_ki;									// write the hull selected to be used in mlp calculations to disk (t) or not (f)
	bool write_x;
	int recon_block_size;									// # of histories in each BIP block, i.e., # of histories used per image update
	int bip_block_size;									// # of histories in each BIP block, i.e., # of histories used per image update
	int bicav_block_size;									// # of histories in each bicav block, i.e., # of histories used per image update
	int drop_block_size;									// # of histories in each drop block, i.e., # of histories used per image update
	int ossart_block_size;									// # of histories in each ossart block, i.e., # of histories used per image update
	int sabicav_block_size;									// # of histories in each bicav block, i.e., # of histories used per image update
	int sadrop_block_size;									// # of histories in each drop block, i.e., # of histories used per image update
	int saossart_block_size;									// # of histories in each ossart block, i.e., # of histories used per image update
	int threads_per_block;									// # of threads per gpu block for preprocessing kernels
    int endpoints_per_block;										// # of threads per gpu block for collect_mlp_endpoints_gpu kernel
	int histories_per_block;										// # of threads per gpu block for block_update_gpu kernel
	int endpoints_per_thread;										// # of mlp endpoints each thread is responsible for calculating in collect_mlp_endpoints_gpu kernel
	int histories_per_thread;										// # of histories each thread is responsible for in mlp/drop kernel block_update_gpu
	int voxels_per_thread;										// # of voxels each thread is responsible for updating for reconstruction image initialization/updates
	int max_gpu_histories;									// [#] number of histories to process on the gpu at a time for preprocessing, based on gpu capacity
	int max_cuts_histories;									// [#] number of histories to process on the gpu at a time for statistical cuts, based on gpu capacity
	int max_endpoints_histories;								// [#] number of histories to process on the gpu at a time for mlp endpoints, based on gpu capacity
	int max_intersections;
  	float gantry_angle_interval;										// [degrees] angle between successive projection angles
	int gantry_angles;		// [#] total number of projection angles
	int num_scans;										// [#] total number of scans
	int num_files;			// [#] 1 file per gantry angle per translation
	float ssd_t_size;									// [cm] length of ssd in t (lateral) direction
	float ssd_v_size;
	float t_shift;										// [cm] amount by which to shift all t coordinates on input
	float u_shift;										// [cm] amount by which to shift all u coordinates on input
	float v_shift;										// [cm] amount by which to shift all v coordinates on input
	float t_bin_size;										// [cm] distance between adjacent bins in t (lateral) direction
	int t_bins;	// [#] number of bins (i.e. quantization levels) for t (lateral) direction
	float v_bin_size;									// [cm] distance between adjacent bins in v (vertical) direction
	int v_bins;		// [#] number of bins (i.e. quantization levels) for v (vertical) direction
	float angular_bin_size;										// [degrees] angle between adjacent bins in angular (rotation) direction
	int angular_bins;		// [#] number of bins (i.e. quantization levels) for path angle
	int num_bins;		// [#] total number of bins corresponding to possible 3-tuples [angular_bin, t_bin, v_bin]
	int sigmas_to_keep;										// [#] number of standard deviations from mean to allow before cutting the history
	float ram_lak_tau;					// defines tau in ram-lak filter calculation, estimated from largest frequency in slice
	float fbp_threshold;
	float recon_cyl_radius;									// [cm] radius of reconstruction cylinder
	float recon_cyl_diameter;				// [cm] diameter of reconstruction cylinder
	float recon_cyl_height;
	float image_width;						// [cm] distance between left and right edges of each slice in image
	float image_height;						// [cm] distance between top and bottom edges of each slice in image
	float image_thickness;			// [cm] distance between bottom of bottom slice and top of the top slice of image
	int columns;										// [#] number of voxels in the x direction (i.e., number of columns) of image
	int rows;										// [#] number of voxels in the y direction (i.e., number of rows) of image
	int slices;// [#] number of voxels in the z direction (i.e., number of slices) of image
	int num_voxels;				// [#] total number of voxels (i.e. 3-tuples [column, row, slice]) in image
	float voxel_width;										// [cm] distance between left and right edges of each voxel in image
	float voxel_height;										// [cm] distance between top and bottom edges of each voxel in image
	float voxel_thickness;									// [cm] distance between top and bottom of each slice in image
	float slice_thickness;
	float sc_lower_threshold;										// [cm] if wepl >= sc_lower_threshold, sc assumes the proton missed the object
	float sc_upper_threshold;										// [cm] if wepl <= sc_upper_threshold, sc assumes the proton missed the object
	float msc_upper_threshold;										// [cm] if wepl >= msc_lower_threshold, msc assumes the proton missed the object
	float msc_lower_threshold;									// [cm] if wepl <= msc_upper_threshold, msc assumes the proton missed the object
	int msc_diff_thresh;										// [#] threshold on difference in counts between adjacent voxels used by msc for edge detection
	float sm_lower_threshold;										// [cm] if wepl >= sm_threshold, sm assumes the proton passed through the object
	float sm_upper_threshold;									// [cm] if wepl > sm_upper_threshold, sm ignores this history
	float sm_scale_threshold;
	float voxel_step_size;						// [cm] length of the step taken along the path, i.e. change in depth per step for
	float mlp_u_step;						// size of the step taken along u direction during mlp; depth difference between successive mlp points
	int max_path_elements; // defines size of gpu array used to store a proton history's mlp voxel #s
	ULL prime_offset;							// Separation between successive histories used in ordering histories for reconstruction
	double eta;								// coefficient of perturbation used in robust methods
	unsigned int method;								// integer indicating the desired robust method to use (deprecated, non in use)
	int psi_sign;								// use a positive (1) or negative (-1) perturbation in robust methods
	float lambda_0;							// initial value of relaxation parameter for case of linear lambda as a function of iteration k, i.e. b in lambda = mk + b -------------------------
	float lambda_m;							// rate of increase of relaxation parameter for case of linear lambda as a function of iteration k, i.e. m in lambda = mk + b ----------------------
	float lambda;							// relaxation parameter to use in image iterative projection reconstruction algorithms
	int iterations;									// # of iterations through the entire set of histories to perform in iterative image reconstruction
	uint sadrop_strings;					// SA-BIP Configuration Option #2: Specifies # of SAP strings separately performing BIP algorithm internally in combined SAP/BIP algorithm
	uint sadrop_blocks_per_string;					// SA-BIP Configuration Option #1: Specifies # of BIP algorithm blocks in each SAP string of combined SAP/BIP algorithm
	//uint sadrop_string_blocks;					// SA-BIP Configuration Option #1: Specifies # of BIP algorithm blocks in each SAP string of combined SAP/BIP algorithm
	bool ignore_short_mlp;									// remove proton histories with short mlp paths from use in reconstruction (on) or not (off)
	int min_mlp_length;									// minimum # of intersections required to use in reconstruction so proton's skimming object are ignored
	bool bound_image;									// if any voxel in the image exceeds 2.0, set it to exactly 2.0
	bool s_curve_on;									//***************************** turn on application of s-curve scaling of updates of voxels near the boundary
	float sigmoid_steepness;								// scaling factor 'k' of logistic curve: 1 / (1 + exp[k(logistic_mid_shift - voxel)])
	int sigmoid_mid_shift;									// x-coordinate where the signoid curve is half of its maximum value
	bool dual_sided_s_curve;									// apply a single-sided (off) or double-sided (on) s-curve attenuation of voxel update values
	bool tvs_on;									// perform total variation superiorization (tvs) during reconstruction
	bool tvs_first;									// perform tvs before (on) or after (off) feasibility seeking during reconstruction
	bool tvs_parallel;									//******************* use the sequential (off) or parallel (on) implementation of tvs
	bool tvs_conditioned;									//****************** verify tvs perturbation improves total variation tv (on) or not (off)
	float tvs_min_beta;								// specify minimum perturbation coefficient to include in precalculated coefficient array
	float tv_threshold;							// [#] value of tv difference ratio |tv_y - tv_y_previous| / tv_y between successive betas where beta is not decreased more
	float alpha;									// perturbation coefficient generation kernel value: beta_k_n = alpha^ell
	float alpha_x0;									// perturbation coefficient generation kernel value applied on initial iterate x_0: beta_n = alpha_x0^ell ----------------------------------
	float perturb_down_factor;							// used in scaling perturbation to yield image w/ reduced perturbation from image previously perturbed w/ larger perturbation
	int ell_0;									// initial value of ell used in calculating the perturbation coefficient: alpha^ell
	int ell_0_x0;									// initial value of ell used in calculating the perturbation coefficient: alpha_x0^ell -----------------------------------------------------
	int ell;								// variable storing perturbation coefficient kernel exponent ell used in calculating the perturbation coefficient: alpha^ell
	float beta_0;								// inital value of tvs perturbation coefficient
	float beta;							// tvs perturbation coefficient
	float beta_k_n;						// Value of BETA used in classical TVS as perturbation coefficient
	UINT n;								// [#] Specifies # of times to perform TVS for each iteration of DROP
	UINT n_x0;								// [#] Specifies # of times to perform TVS on initial iterate x_0 ----------------------------------------------------------------------------------
	bool avg_filter_fbp;
	bool avg_filter_hull;								// apply averaging filter to hull (t) or not (f)
	bool avg_filter_x_0;							// apply averaging filter to initial iterate (t) or not (f)
	bool median_filter_fbp;								// apply median filter to fbp (t) or not (f)
	bool median_filter_hull;								// apply median filter to hull (t) or not (f)
	bool median_filter_x_0;							// Apply averaging filter to initial iterate (T) or not (F)
	bool superiorize_x_0;							// Apply averaging filter to initial iterate (T) or not (F)  ---------------------------------------------------------------------------------
	UINT hull_avg_filter_radius;								// [#] Radius of the average filter to apply to hull image
	UINT fbp_avg_filter_radius;								// [#] Radius of the average filter to apply to FBP image
	UINT x_0_avg_filter_radius;								// [#] Radius of the average filter to apply to initial iterate
	UINT fbp_med_filter_radius;								// [#] Radius of the median filter to apply to hull image
	UINT hull_med_filter_radius;								// [#] Radius of the median filter to apply to FBP image
	UINT x_0_med_filter_radius;								// [#] Radius of the median filter to apply to initial iterate
	double hull_avg_filter_threshold;								// [#] threshold applied to average filtered hull separating voxels to include/exclude from hull (i.e. set to 0/1)
	double fbp_avg_filter_threshold;								// [#] threshold applied to average filtered fbp separating voxels to include/exclude from fbp hull (i.e. set to 0/1)
	double x_0_avg_filter_threshold;								// [#] threshold applied to average filtered initial iterate below which a voxel is excluded from reconstruction (i.e. set to 0)
	char tested_by_string[50];
	char code_owner[50];							// karbasip, plautzt, giacomettiv, zatserkl, penfolds, wittm, master
	char program_version[50];
	char section_exit_string[50];
	char true_string[50];
	char false_string[50];
	char on_string[50];
	char off_string[50];
	char my_recon_dir[100];
	char current_git_branch[30];
	char tardis_rcode_dir[100];
    bool perturb_A;
	float perturbation_parameter;
	int max_histories_2_remove;
  	UINT size_bins_char;
  	UINT size_bins_bool;
  	uint size_bins_int;
  	UINT size_bins_uint;
  	UINT size_bins_float;
  	UINT size_image_char;
  	UINT size_image_bool;
  	UINT size_image_int;
  	UINT size_image_uint;
  	UINT size_image_float;
  	UINT size_image_double;
	float x_zero_coordinate;
  	float y_zero_coordinate;
	float z_zero_coordinate;
	float source_radius;
	float trig_table_step;
	bool run_on_kodiak;
	unsigned int current_iterate;
} pCTparams;
configurations parameter_container;
configurations *configurations_h = &parameter_container;
configurations *configurations_d;

void construct_pCT_params()
{
	//std::vector<PCT_PARAMS> pct_params;
	//pct_params.push_back(PCT_PARAMS(configurations_h, std::string("rand_engine"), ENUM));
	//size_t offset = offsetof(configurations,rand_engine);
	//int* pointerToC = (int*)((char*)&configurations_h + offset);
	//auto b = (&configurations_h +offset);
	//auto dd = (configurations::)(1);
	//cout << (*b) << endl;
	//int* pointerToC = (int*)((char*)&configurations_h + offset);
	//cout << pCTparams[0]  << endl;
}

//cfgdef_enum_parameter(configurations_h->rand_engine, "rand_engine" , cfgdef_optname );	// 1
//
//std::vector<> pCT_params =
//{
//    {"rand_engine", required_argument, NULL, 1},
//    {"tvs_rand_engine", required_argument, NULL, 2},
//    {"scan_type", required_argument, NULL, 3},
//    {"file_type", required_argument, NULL, 4},
//    {"data_format", required_argument, NULL, 5},
//    {"image_basis", required_argument, NULL, 6},
//    {"fbp_filter", required_argument, NULL, 7},
//    {"endpoints_hull", required_argument, NULL, 8},
//    {"x_0", required_argument, NULL, 9},
//    {"endpoints_alg", required_argument, NULL, 10},
//    {"endpoints_tx_mode", required_argument, NULL, 11},
//    {"mlp_algorithm", required_argument, NULL, 12},
//    {"projection_algorithm", required_argument, NULL, 13},
//    {"recon_tx_mode", required_argument, NULL, 14},
//    {"drop_tx_mode", required_argument, NULL, 15},
//    {"s_curve", required_argument, NULL, 16},
//    {"robust_method", required_argument, NULL, 17},
//    {"run_on", required_argument, NULL, 18},
//    {"testing_on", required_argument, NULL, 19},
//    {"block_testing_on", required_argument, NULL, 20},
//    {"s_curve_testing_on", required_argument, NULL, 21},
//    {"ntvs_testing_on", required_argument, NULL, 22},
//    {"overwriting_ok", required_argument, NULL, 23},
//    {"exit_after_binning", required_argument, NULL, 24},
//    {"exit_after_hulls", required_argument, NULL, 25},
//    {"exit_after_cuts", required_argument, NULL, 26},
//    {"exit_after_sinogram", required_argument, NULL, 27},
//    {"exit_after_fbp", required_argument, NULL, 28},
//    {"close_after_execution", required_argument, NULL, 29},
//    {"debug_text_on", required_argument, NULL, 30},
//    {"sample_std_dev", required_argument, NULL, 31},
//    {"fbp_on", required_argument, NULL, 32},
//    {"import_filtered_fbp", required_argument, NULL, 33},
//    {"sc_on", required_argument, NULL, 34},
//    {"msc_on", required_argument, NULL, 35},
//    {"sm_on", required_argument, NULL, 36},
//    {"count_0_wepls", required_argument, NULL, 37},
//    {"direct_image_reconstruction", required_argument, NULL, 38},
//    {"mlp_file_exists", required_argument, NULL, 39},
//    {"mlp_endpoints_file_exists", required_argument, NULL, 40},
//    {"input_directory", required_argument, NULL, 41},
//    {"output_directory", required_argument, NULL, 42},
//    {"input_folder", required_argument, NULL, 43},
//    {"output_folder", required_argument, NULL, 44},
//    {"binary_encoding", required_argument, NULL, 45},
//    {"single_data_file", required_argument, NULL, 46},
//    {"ssd_in_mm", required_argument, NULL, 47},
//    {"data_in_mm", required_argument, NULL, 48},
//    {"micah_sim", required_argument, NULL, 49},
//    {"write_bin_wepls", required_argument, NULL, 50},
//    {"write_wepl_dists", required_argument, NULL, 51},
//    {"write_ssd_angles", required_argument, NULL, 52},
//    {"write_sc_hull", required_argument, NULL, 53},
//    {"write_msc_counts", required_argument, NULL, 54},
//    {"write_msc_hull", required_argument, NULL, 55},
//    {"write_sm_counts", required_argument, NULL, 56},
//    {"write_sm_hull", required_argument, NULL, 57},
//    {"write_fbp_image", required_argument, NULL, 58},
//    {"write_fbp_hull", required_argument, NULL, 59},
//    {"write_avg_fbp", required_argument, NULL, 60},
//    {"write_median_fbp", required_argument, NULL, 61},
//    {"write_filtered_hull", required_argument, NULL, 62},
//    {"write_x_hull", required_argument, NULL, 63},
//    {"write_x_0", required_argument, NULL, 64},
//    {"write_x_ki", required_argument, NULL, 65},
//    {"write_x", required_argument, NULL, 66},
//    {"drop_block_size", required_argument, NULL, 67},
//    {"threads_per_block", required_argument, NULL, 68},
//    {"endpoints_per_block", required_argument, NULL, 69},
//    {"histories_per_block", required_argument, NULL, 70},
//    {"endpoints_per_thread", required_argument, NULL, 71},
//    {"histories_per_thread", required_argument, NULL, 72},
//    {"voxels_per_thread", required_argument, NULL, 73},
//    {"max_gpu_histories", required_argument, NULL, 74},
//    {"max_cuts_histories", required_argument, NULL, 75},
//    {"max_endpoints_histories", required_argument, NULL, 76},
//    {"max_intersections", required_argument, NULL, 77},
//    {"gantry_angle_interval", required_argument, NULL, 78},
//    {"num_scans", required_argument, NULL, 79},
//    {"ssd_t_size", required_argument, NULL, 80},
//    {"ssd_v_size", required_argument, NULL, 81},
//    {"t_shift", required_argument, NULL, 82},
//    {"u_shift", required_argument, NULL, 83},
//    {"v_shift", required_argument, NULL, 84},
//    {"t_bin_size", required_argument, NULL, 85},
//    {"v_bin_size", required_argument, NULL, 86},
//    {"angular_bin_size", required_argument, NULL, 87},
//    {"sigmas_to_keep", required_argument, NULL, 88},
//    {"fbp_threshold", required_argument, NULL, 89},
//    {"recon_cyl_radius", required_argument, NULL, 90},
//    {"slice_thickness", required_argument, NULL, 91},
//    {"voxel_width", required_argument, NULL, 92},
//    {"voxel_height", required_argument, NULL, 93},
//    {"voxel_thickness", required_argument, NULL, 94},
//    {"sc_lower_threshold", required_argument, NULL, 95},
//    {"sc_upper_threshold", required_argument, NULL, 96},
//    {"msc_upper_threshold", required_argument, NULL, 97},
//    {"msc_lower_threshold", required_argument, NULL, 98},
//    {"msc_diff_thresh", required_argument, NULL, 99},
//    {"sm_lower_threshold", required_argument, NULL, 100},
//    {"sm_upper_threshold", required_argument, NULL, 101},
//    {"sm_scale_threshold", required_argument, NULL, 102},
//    {"voxel_step_size", required_argument, NULL, 103},
//    {"prime_offset", required_argument, NULL, 104},
//    {"eta", required_argument, NULL, 105},
//    {"method", required_argument, NULL, 106},
//    {"psi_sign", required_argument, NULL, 107},
//    {"lambda", required_argument, NULL, 108},
//    {"iterations", required_argument, NULL, 109},
//    {"ignore_short_mlp", required_argument, NULL, 110},
//    {"min_mlp_length", required_argument, NULL, 111},
//    {"bound_image", required_argument, NULL, 112},
//    {"s_curve_on", required_argument, NULL, 113},
//    {"sigmoid_steepness", required_argument, NULL, 114},
//    {"sigmoid_mid_shift", required_argument, NULL, 115},
//    {"dual_sided_s_curve", required_argument, NULL, 116},
//    {"tvs_on", required_argument, NULL, 117},
//    {"tvs_first", required_argument, NULL, 118},
//    {"tvs_parallel", required_argument, NULL, 119},
//    {"tvs_conditioned", required_argument, NULL, 120},
//    {"tvs_min_beta", required_argument, NULL, 121},
//    {"tv_threshold", required_argument, NULL, 122},
//    {"alpha", required_argument, NULL, 123},
//    {"ell_0", required_argument, NULL, 124},
//    {"ell", required_argument, NULL, 125},
//    {"beta_0", required_argument, NULL, 126},
//    {"beta", required_argument, NULL, 127},
//    {"n", required_argument, NULL, 128},
//    {"avg_filter_fbp", required_argument, NULL, 129},
//    {"avg_filter_hull", required_argument, NULL, 130},
//    {"avg_filter_x_0", required_argument, NULL, 131},
//    {"median_filter_fbp", required_argument, NULL, 132},
//    {"median_filter_hull", required_argument, NULL, 133},
//    {"median_filter_x_0", required_argument, NULL, 134},
//    {"hull_avg_filter_radius", required_argument, NULL, 135},
//    {"fbp_avg_filter_radius", required_argument, NULL, 136},
//    {"x_0_avg_filter_radius", required_argument, NULL, 137},
//    {"fbp_med_filter_radius", required_argument, NULL, 138},
//    {"hull_med_filter_radius", required_argument, NULL, 139},
//    {"x_0_med_filter_radius", required_argument, NULL, 140},
//    {"hull_avg_filter_threshold", required_argument, NULL, 141},
//    {"fbp_avg_filter_threshold", required_argument, NULL, 142},
//    {"x_0_avg_filter_threshold", required_argument, NULL, 143},
//    {"tested_by_string", required_argument, NULL, 144},
//    {"code_owner", required_argument, NULL, 145},
//    {"program_version", required_argument, NULL, 146},
//    {"section_exit_string", required_argument, NULL, 147},
//    {"my_recon_dir", required_argument, NULL, 148},
//    {"current_git_branch", required_argument, NULL, 149},
//    {"tardis_rcode_dir", required_argument, NULL, 150},
//    {"perturb_A", required_argument, NULL, 151},
//    {"perturbation_parameter", required_argument, NULL, 152},
//    {"max_histories_2_remove", required_argument, NULL, 153},
//    {"source_radius", required_argument, NULL, 154},
//    {"trig_table_step", required_argument, NULL, 155},
//    {"run_on_kodiak", required_argument, NULL, 156},
//    {"lambda_k_type", required_argument, NULL, 157},
//    {"lambda_0", required_argument, NULL, 158},
//	{"lambda_m", required_argument, NULL, 159},
//    {"alpha_x0", required_argument, NULL, 160},
//    {"ell_0_x0", required_argument, NULL, 161},
//    {"n_x0", required_argument, NULL, 162},
//    {"superiorize_x_0", required_argument, NULL, 163},
//    {"sabip_config", required_argument, NULL, 164},
//    {"sadrop_strings", required_argument, NULL, 165},
//    {"sadrop_blocks_per_string", required_argument, NULL, 166},
//    //{"sadrop_string_blocks", required_argument, NULL, 166},
//	{"block_ordering", required_argument, NULL, 167},
//	{"bicav_block_size", required_argument, NULL, 168},
//	{"ossart_block_size", required_argument, NULL, 169,
//	{"sabicav_block_size", required_argument, NULL, 170},
//	{"sadrop_block_size", required_argument, NULL, 171},
//	{"saossart_block_size", required_argument, NULL, 172},
//	{"recon_block_size", required_argument, NULL, 173},
//    /*{"workstation_1_hostname", required_argument, NULL, 172},
//    {"workstation_2_hostname", required_argument, NULL, 173},
//    {"kodiak_hostname", required_argument, NULL, 174},
//    {"whartnell_hostname", required_argument, NULL, 175},
//    {"whartnell_ID", required_argument, NULL, 176},
//    {"jpertwee_ID", required_argument, NULL, 177},
//    {"jpertwee_hostname", required_argument, NULL, 178},
//    {"bash_secure_copy", required_argument, NULL, 179},
//    {"bash_copy_dir", required_argument, NULL, 180},
//    {"bash_copy_file", required_argument, NULL, 181},
//    {"baylor_username", required_argument, NULL, 182},
//    {"cluster_username", required_argument, NULL, 183},
//    {"kodiak_login", required_argument, NULL, 184},
//    {"whartnell_login", required_argument, NULL, 185},
//    {"ptroughton_login", required_argument, NULL, 186},
//    {"jpertwee_login", required_argument, NULL, 187},
//    {"tbaker_login", required_argument, NULL, 188},
//    {"pdavison_login", required_argument, NULL, 189},
//    {"pct_path_global", required_argument, NULL, 190},
//    {"pct_path_tardis", required_argument, NULL, 191},
//    {"pct_data_dir", required_argument, NULL, 192},
//    {"pct_code_dir", required_argument, NULL, 193},
//    {"pct_recon_dir", required_argument, NULL, 194},
//    {"pct_recon_path", required_argument, NULL, 195},
//    {"my_data_dir", required_argument, NULL, 196},
//    {"my_recon_dir", required_argument, NULL, 197},
//    {"my_code_dir", required_argument, NULL, 198},
//    {"ws2_code_dir", required_argument, NULL, 199},
//    {"ws2_recon_dir", required_argument, NULL, 200},
//    {"jpertwee_code_dir", required_argument, NULL, 201},
//    {"jpertwee_recon_dir", required_argument, NULL, 202},
//    {"whartnell_code_dir", required_argument, NULL, 203},
//    {"whartnell_recon_dir", required_argument, NULL, 204},
//    {"pct_data_folder", required_argument, NULL, 205},
//    {"pct_code_folder", required_argument, NULL, 206},
//    {"raw_data_folder", required_argument, NULL, 207},
//    {"processed_data_folder", required_argument, NULL, 208},
//    {"projection_data_folder", required_argument, NULL, 209},
//    {"recon_data_folder", required_argument, NULL, 210},
//    {"organized_data_folder", required_argument, NULL, 211},
//    {"experimental_folder", required_argument, NULL, 212},
//    {"simulated_folder", required_argument, NULL, 213},
//    {"geant4_dir_prefix", required_argument, NULL, 214},
//    {"topas_dir_prefix", required_argument, NULL, 215},
//    {"raw_links_folder", required_argument, NULL, 216},
//    {"projection_links_folder", required_argument, NULL, 217},
//    {"reconstruction_folder", required_argument, NULL, 218},
//    {"hostname_cmd", required_argument, NULL, 219},
//    {"username_cmd", required_argument, NULL, 220},
//    {"userid_cmd", required_argument, NULL, 221},
//    {"groupname_cmd", required_argument, NULL, 222},
//    {"groupid_cmd", required_argument, NULL, 223},
//    {"groupnames_cmd", required_argument, NULL, 224},
//    {"groupids_cmd", required_argument, NULL, 225},
//    {"hostname_envvar", required_argument, NULL, 226},
//    {"home_dir_envvar", required_argument, NULL, 227},
//    {"username_envvar", required_argument, NULL, 228},
//    {"userid_envvar", required_argument, NULL, 229},
//    {"userid_effect_envvar", required_argument, NULL, 230},
//    {"groups_envvar", required_argument, NULL, 231},
//    {"ostype_envvar", required_argument, NULL, 232},
//    {"path_envvar", required_argument, NULL, 233},
//    {"work_dir_envvar", required_argument, NULL, 234},
//    {"owner_access", required_argument, NULL, 235},
//    {"group_access", required_argument, NULL, 236},
//    {"global_access", required_argument, NULL, 237},
//    {"input_base_name", required_argument, NULL, 238},
//    {"file_extension", required_argument, NULL, 239},
//    {"config_filename", required_argument, NULL, 240},
//    {"config_out_filename", required_argument, NULL, 241},
//    {"log_filename", required_argument, NULL, 242},
//    {"stdout_filename", required_argument, NULL, 243},
//    {"stdin_filename", required_argument, NULL, 244},
//    {"stderr_filename", required_argument, NULL, 245},
//    {"execution_times_fname", required_argument, NULL, 246},
//    {"sin_table_fname", required_argument, NULL, 247},
//    {"cos_table_fname", required_argument, NULL, 248},
//    {"coefficient_fname", required_argument, NULL, 249},
//    {"poly_1_2_fname", required_argument, NULL, 250},
//    {"poly_2_3_fname", required_argument, NULL, 251},
//    {"poly_3_4_fname", required_argument, NULL, 252},
//    {"poly_2_6_fname", required_argument, NULL, 253},
//    {"poly_3_12_fname", required_argument, NULL, 254},
//    {"sc_hull_fname", required_argument, NULL, 255},
//    {"msc_hull_fname", required_argument, NULL, 256},
//    {"sm_hull_fname", required_argument, NULL, 257},
//    {"fbp_hull_fname", required_argument, NULL, 258},
//    {"sm_counts_fname", required_argument, NULL, 259},
//    {"msc_counts_fname", required_argument, NULL, 260},
//    {"hull_fname", required_argument, NULL, 261},
//    {"hull_avg_filter_fname", required_argument, NULL, 262},
//    {"hull_med_filter_fname", required_argument, NULL, 263},
//    {"input_hull_fname", required_argument, NULL, 264},
//    {"sinogram_fname", required_argument, NULL, 265},
//    {"sinogram_pre_fname", required_argument, NULL, 266},
//    {"fbp_fname", required_argument, NULL, 267},
//    {"fbp_after_fname", required_argument, NULL, 268},
//    {"fbp_image_filter_fname", required_argument, NULL, 269},
//    {"fbp_med_filter_fname", required_argument, NULL, 270},
//    {"fbp_avg_filter_filename", required_argument, NULL, 271},
//    {"input_iterate_fname", required_argument, NULL, 272},
//    {"import_fbp_fname", required_argument, NULL, 273},
//    {"x_0_fname", required_argument, NULL, 274},
//    {"x_fname", required_argument, NULL, 275},
//    {"bin_counts_pre_fname", required_argument, NULL, 276},
//    {"bin_counts_fname", required_argument, NULL, 277},
//    {"bin_counts_post_fname", required_argument, NULL, 278},
//    {"mean_wepl_fname", required_argument, NULL, 279},
//    {"mean_rel_ut_fname", required_argument, NULL, 280},
//    {"mean_rel_uv_fname", required_argument, NULL, 281},
//    {"stddev_rel_ut_fname", required_argument, NULL, 282},
//    {"stddev_rel_uv_fname", required_argument, NULL, 283},
//    {"stddev_wepl_fname", required_argument, NULL, 284},
//    {"mlp_paths_fname", required_argument, NULL, 285},
//    {"mlp_paths_error_fname", required_argument, NULL, 286},
//    {"mlp_endpoints_fname", required_argument, NULL, 287},
//    {"old_format_string", required_argument, NULL, 288},
//    {"version_0_string", required_argument, NULL, 289},
//    {"version_1_string", required_argument, NULL, 290},
//    {"experimental_string", required_argument, NULL, 291},
//    {"simulated_g_string", required_argument, NULL, 292},
//    {"simulated_t_string", required_argument, NULL, 293},
//    {"text_string", required_argument, NULL, 294},
//    {"binary_string", required_argument, NULL, 295},
//    {"default_rand_string", required_argument, NULL, 296},
//    {"minstd_rand_string", required_argument, NULL, 297},
//    {"minstd_rand0_string", required_argument, NULL, 298},
//    {"mt19937_string", required_argument, NULL, 299},
//    {"mt19937_64_string", required_argument, NULL, 300},
//    {"randlux24_string", required_argument, NULL, 301},
//    {"randlux48_string", required_argument, NULL, 302},
//    {"knuth_b_string", required_argument, NULL, 303},
//    {"voxels_string", required_argument, NULL, 304},
//    {"blobs_string", required_argument, NULL, 305},
//    {"means_string", required_argument, NULL, 306},
//    {"counts_string", required_argument, NULL, 307},
//    {"members_string", required_argument, NULL, 308},
//    {"all_bins_string", required_argument, NULL, 309},
//    {"specific_bins_string", required_argument, NULL, 310},
//    {"by_bin_string", required_argument, NULL, 311},
//    {"by_history_string", required_argument, NULL, 312},
//    {"wepls_string", required_argument, NULL, 313},
//    {"angles_string", required_argument, NULL, 314},
//    {"positions_string", required_argument, NULL, 315},
//    {"bin_nums_string", required_argument, NULL, 316},
//    {"ram_lak_string", required_argument, NULL, 317},
//    {"shepp_logan_string", required_argument, NULL, 318},
//    {"none_string", required_argument, NULL, 319},
//    {"sc_hull_string", required_argument, NULL, 320},
//    {"msc_hull_string", required_argument, NULL, 321},
//    {"sm_hull_string", required_argument, NULL, 322},
//    {"fbp_hull_string", required_argument, NULL, 323},
//    {"x_hull_string", required_argument, NULL, 324},
//    {"hull_string", required_argument, NULL, 325},
//    {"fbp_image_string", required_argument, NULL, 326},
//    {"hybrid_string", required_argument, NULL, 327},
//    {"zeros_string", required_argument, NULL, 328},
//    {"import_string", required_argument, NULL, 329},
//    {"full_tx_string", required_argument, NULL, 330},
//    {"partial_tx_string", required_argument, NULL, 331},
//    {"partial_tx_preallocated_string", required_argument, NULL, 332},
//    {"bool_string", required_argument, NULL, 333},
//    {"yes_bool_string", required_argument, NULL, 334},
//    {"no_bool_string", required_argument, NULL, 335},
//    {"standard_string", required_argument, NULL, 336},
//    {"tabulated_string", required_argument, NULL, 337},
//    {"art_string", required_argument, NULL, 338},
//    {"sart_string", required_argument, NULL, 339},
//    {"drop_string", required_argument, NULL, 340},
//    {"bip_string", required_argument, NULL, 341},
//    {"sap_string", required_argument, NULL, 342},
//    {"robusta_string", required_argument, NULL, 343},
//    {"robustb_string", required_argument, NULL, 344},
//    {"sigmoid_string", required_argument, NULL, 345},
//    {"tanh_string", required_argument, NULL, 346},
//    {"atan_string", required_argument, NULL, 347},
//    {"erf_string", required_argument, NULL, 348},
//    {"lin_over_root_string", required_argument, NULL, 349},
//    {"ols_string", required_argument, NULL, 350},
//    {"tls_string", required_argument, NULL, 351},
//    {"tikhonov_string", required_argument, NULL, 352},
//    {"ridge_string", required_argument, NULL, 353},
//    {"minmin_string", required_argument, NULL, 354},
//    {"minmax_string", required_argument, NULL, 355},
//    {"square_string", required_argument, NULL, 356},
//    {"disk_string", required_argument, NULL, 357},
//    {"erosion_string", required_argument, NULL, 358},
//    {"dilation_string", required_argument, NULL, 359},
//    {"opening_string", required_argument, NULL, 360},
//    {"closing_string", required_argument, NULL, 361},
//    {"object_l_string", required_argument, NULL, 362},
//    {"scan_type_l_string", required_argument, NULL, 363},
//    {"run_date_l_string", required_argument, NULL, 364},
//    {"run_number_l_string", required_argument, NULL, 365},
//    {"max_iterations", required_argument, NULL, 366},
//    {"e_0", required_argument, NULL, 367},
//    {"x0", required_argument, NULL, 368},
//    {"rsp_air", required_argument, NULL, 369},
//    {"beam_energy", required_argument, NULL, 370},
//    {"source_radius", required_argument, NULL, 371},
//    {"a_0", required_argument, NULL, 372},
//    {"a_1", required_argument, NULL, 373},
//    {"a_2", required_argument, NULL, 374},
//    {"a_3", required_argument, NULL, 375},
//    {"a_4", required_argument, NULL, 376},
//    {"a_5", required_argument, NULL, 377},*/
//    {NULL, 0, NULL, 0}
//};
