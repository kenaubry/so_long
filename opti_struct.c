
typedef struct s_image
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			h;
	int			w;
	int 		pos_x;
	int			pos_y;
	int 		exit;
	int			mvmts;
	//char		*path;
}				t_image;

#define TEXT_NBR 7
enum obj
{
	player,
	player2,
	walls,
	collectibles,
	exit,
	background,
	dark
};


static const char *textures_path[TEXT_NBR] =
{
	"./sprites/player_right.xpm",
	"./sprites/player_left.xpm",
	"./sprites/walls.xpm",
	"./sprites/collectibles.xpm",
	"./sprites/exit.xpm",
	"./sprites/background.xpm",
	"./sprites/dark.xpm"
};



typedef struct	s_data
{
	void    *mlx;
    void    *win;
	// ce genre de struct passe mais un tableau de struct est mieux pour stocker les images et les textures
	// t_image	*textures[10];
	// avec enum obj { player, player2, walls, collectibles, etc... }
	// tu mets les index a NULL au depart
	// je vais te faire un exemple de code dans un fichers opti_struct.c
	t_image	*textures[TEXT_NBR];
	int		collect;
	char	**map;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		fd;
	int		read;
	int		mvmnt;
	int 	direction;
}				t_data; // 5 à free


#define text_i mlx->textures[i]


int open_textures(t_data *data){

	int i;

	i = 0;
	while(i < TEXT_NBR){
		data->textures[i]->img = mlx_xpm_file_to_image(data->mlx, textures_path[i], &data->textures[i]->w, &data->textures[i]->h);
		if(data->textures[i]->img == NULL)
			return (-1);// free dans la fonction mere

		data->textures[i]->addr = mlx_get_data_addr(data->textures[i]->img, &data->textures[i]->bits_per_pixel,
								 &data->textures[i]->line_length, &data->textures[i]->endian);
		i++;
	}

	return 0;
}





