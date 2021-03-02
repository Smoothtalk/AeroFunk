# 1 "game.c" 1
# 1 "C:/c68/include/osbind.h" 1
# 1 "C:/c68/include/compiler.h" 1
# 9 "C:/c68/include/osbind.h" 2
# 1 "C:/c68/include/ostruct.h" 1
# 22 "C:/c68/include/ostruct.h"
typedef struct {
    long b_free;
    long b_total;
    long b_secsiz;
    long b_clsiz;
} _DISKINFO;


typedef struct {
  short time;
  short date;
} _DOSTIME;


typedef struct
{
        unsigned char maxlen;
        unsigned char actuallen;
        char    buffer[255];
} _CCONLINE;
# 48 "C:/c68/include/ostruct.h"
typedef struct _dta {
    char 	    dta_buf[21];
    char            dta_attribute;
    unsigned short  dta_time;
    unsigned short  dta_date;
    long            dta_size;
    char            dta_name[14];
} _DTA;
# 98 "C:/c68/include/ostruct.h"
typedef struct {
  short recsiz;
  short clsiz;
  short clsizb;
  short rdlen;
  short fsiz;
  short fatrec;
  short datrec;
  short numcl;
  short bflags;
} _BPB;




typedef struct _md {
    struct _md	*md_next;
    long	 md_start;
    long	 md_length;
    long	 md_owner;
} _MD;


typedef struct {
    _MD *mp_free;
    _MD *mp_used;
    _MD *mp_rover;
} _MPB;
# 141 "C:/c68/include/ostruct.h"
typedef struct {
    char    *ibuf;
    short   ibufsiz;
    volatile short   ibufhd;
    volatile short   ibuftl;
    short   ibuflow;
    short   ibufhi;
} _IOREC;


typedef struct {
	char	topmode;
	char	buttons;
	char	xparam;
	char	yparam;
	short	xmax;
	short	ymax;
	short	xstart;
	short	ystart;
} _PARAM;


typedef struct {
    void    (*midivec)	(void) ;
    void    (*vkbderr)	(void) ;
    void    (*vmiderr)	(void) ;
    void    (*statvec)	(void *) ;
    void    (*mousevec)	(void *) ;
    void    (*clockvec)	(void *) ;
    void    (*joyvec)	(void *) ;
    long    (*midisys)	(void) ;
    long    (*ikbdsys)	(void) ;
    char    kbstate;
} _KBDVECS;


typedef struct {
    void *unshift;
    void *shift;
    void *caps;
} _KEYTAB;


typedef struct
{
        void    *pb_scrptr;
        int     pb_offset;
        int     pb_width;
        int     pb_height;
        int     pb_left;
        int     pb_right;
        int     pb_screz;
        int     pb_prrez;
        void    *pb_colptr;
        int     pb_prtype;
        int     pb_prport;
        void    *pb_mask;
} _PBDEF;
# 17 "C:/c68/include/osbind.h" 2
# 33 "C:/c68/include/osbind.h"
 long _trap_1_w		(short) ;
 long _trap_1_ww	(short,short) ;
 long _trap_1_wl	(short,long) ;
 long _trap_1_wlw	(short,long,short) ;
 long _trap_1_wwll	(short,short,long,long) ;
 long _trap_1_wlww	(short,long,short,short) ;
 long _trap_1_www	(short,short,short) ;
 long _trap_1_wll	(short,long,long) ;
 long _trap_1_wwlll	(short,short,long,long,long) ;
 long _trap_1_wwwll	(short,short,short,long,long) ;
 long _trap_13_wl	(short,long) ;
 long _trap_13_w	(short) ;
 long _trap_13_ww	(short,short) ;
 long _trap_13_www	(short,short,short) ;
 long _trap_13_wwlwww	(short,short,long,short,short,short) ;
 long _trap_13_wwl	(short,short,long) ;
 long _trap_14_wwl	(short,short,long) ;
 long _trap_14_wwll	(short,short,long,long) ;
 long _trap_14_ww	(short,short) ;
 long _trap_14_w	(short) ;
 long _trap_14_wllw	(short,long,long,short) ;
 long _trap_14_wl	(short,long) ;
 long _trap_14_www	(short,short,short) ;
 long _trap_14_wllwwwww (short,long,long,short,short,short,short,short) ;
 long _trap_14_wllwwwwlw (short,long,long,short,short,short,short,long,short) ;
 long _trap_14_wllwwwwwlw (short,long,long,short,short,short,short,short,long,short) ;
 long _trap_14_wwwwwww	(short,short,short,short,short,short,short) ;
 long _trap_14_wlll	(short,long,long,long) ;
 long _trap_14_wllww	(short,long,long,short,short) ;
 long _trap_14_wwwwl	(short,short,short,short,long) ;
 long _trap_14_wwwl	(short,short,short,long) ;
 long _trap_14_wlwlw	(short,long,short,long,short) ;
# 103 "C:/c68/include/osbind.h"
 long _trap_1_ 	(short,...) ;
 long _trap_14_ 	(short,...) ;
 long _trap_13_ 	(short,...) ;
# 1 "game.c" 2
# 1 "C:/c68/include/stdlib.h" 1
# 18 "C:/c68/include/stdlib.h"
typedef unsigned long  size_t;




typedef char  wchar_t;
# 44 "C:/c68/include/stdlib.h"
typedef struct {
    int		quot;
    int		rem;
} div_t;

typedef struct {
    long	quot;
    long	rem;
} ldiv_t;

 double atof (const char *s) ;
 int atoi (const char *str) ;
 long atol (const char *str) ;
 long int strtol (const char *nptr, char **endptr, int base) ;
 unsigned long int strtoul (const char *nptr, char **endptr, int base) ;
 double strtod (const char *s, char **endptr) ;

 void srand (unsigned int seed) ;
 int rand (void) ;

 void *malloc (size_t n) ;
 void free (void *param) ;
 void *realloc (void *_r, size_t n) ;
 void *calloc (size_t n, size_t sz) ;





 void *alloca (size_t) ;
# 89 "C:/c68/include/stdlib.h"
 void  abort (void) ;


 int atexit (void (*)(void)) ;

 void  exit (int) ;

 char *getenv (const char *tag) ;
 int system (const char *s) ;

 void *bsearch (const void *key, const void *base, size_t num, size_t size, int (*cmp )(const void *, const void *)) ;
 void qsort (void *base, size_t total_elems, size_t size, int (*cmp )(const void *, const void *)) ;

 int abs (int x) ;
 long labs (long x) ;

 div_t div (int num, int denom) ;
 ldiv_t ldiv (long num, long denom) ;

 int mblen (const char *, size_t) ;
 size_t mbstowcs (wchar_t *, const char *, size_t) ;
 int mbtowc (wchar_t *, const char *, size_t) ;
 size_t wcstombs (char *, const wchar_t *, size_t) ;
 int wctomb (char *, wchar_t) ;

 wchar_t *wcscat (wchar_t *, const wchar_t *) ;
 int wcscmp (const wchar_t *, const wchar_t *) ;
 wchar_t *wcscpy (wchar_t *, const wchar_t *) ;
 size_t wcslen (const wchar_t *) ;
 wchar_t *wcsncat (wchar_t *, const wchar_t *, size_t) ;
 int wcsncmp (const wchar_t *, const wchar_t *, size_t) ;
 wchar_t *wcsncpy (wchar_t *, const wchar_t *, size_t) ;
# 2 "game.c" 2
# 1 "C:/c68/include/string.h" 1
# 25 "C:/c68/include/string.h"
 void *memcpy (void *dst, const void *src, size_t size) ;
 void *memmove (void *dst, const void *src, size_t size) ;
 int memcmp (const void *s1, const void *s2, size_t size) ;
 void *memchr (const void *s, int ucharwanted, size_t size) ;
 void *memset (void *s, int ucharfill, size_t size) ;

 char *strcpy (char *dst, const char *src) ;
 char *strncpy (char *dst, const char *src, size_t n) ;
 char *strcat (char *dst, const char *src) ;
 char *strncat (char *dst, const char *src, size_t n) ;
 int strcmp (const char *scan1, const char *scan2) ;
 int strncmp (const char *scan1, const char *scan2, size_t n) ;
 int strcoll (const char *scan1, const char *scan2) ;
 size_t	strxfrm (char *to, const char *from, size_t maxsize) ;
 char *strchr (const char *s, int charwanted) ;
 size_t strcspn (const char *s, const char *reject) ;
 char *strpbrk (const char *s, const char *breakat) ;
 char *strrchr (const char *s, int charwanted) ;
 size_t strspn (const char *s, const char *accept) ;
 char *strstr (const char *s, const char *wanted) ;
 char *strtok (char *s, const char *delim) ;
 size_t strlen (const char *scan) ;
 char *strerror (int errnum) ;
# 54 "C:/c68/include/string.h"
 void *memccpy (void *dst, const void *src, int ucharstop, size_t size) ;
 char *strlwr (char *string) ;
 char *strupr (char *string) ;



 char *strrev (char *string) ;
 char *strdup (const char *s) ;




 char *index (const char *s, int charwanted) ;
 char *rindex (const char *s, int charwanted) ;
 void bcopy (const void *src, void *dst, size_t length) ;
 int bcmp (const void *src, const void *dst, size_t n) ;
 void bzero (void *b, size_t n) ;

 void _bcopy (const void *src, void *dst, unsigned long length) ;
 int  _bcmp (const void *s1, const void *s2, unsigned long length) ;
 void _bzero (void *dst, unsigned long length) ;

 int stricmp ( const char *, const char * ) ;
 int strnicmp ( const char *, const char *, size_t ) ;
 int strcmpi ( const char *, const char * ) ;
 int strncmpi ( const char *, const char *, size_t ) ;
# 3 "game.c" 2
# 1 "./GAME.H" 1
# 1 "C:/c68/include/stdio.h" 1
# 69 "C:/c68/include/stdio.h"
typedef	struct
	{
	long		_cnt;
	unsigned char	*_ptr;
	unsigned char	*_base;
	unsigned int	_flag;
	int		_file;
	long		_bsiz;
	unsigned char	_ch;
	}
	FILE;


typedef unsigned long fpos_t;
# 92 "C:/c68/include/stdio.h"
extern	FILE	_iob[];
# 108 "C:/c68/include/stdio.h"
 char *	ctermid	(char *) ;




 int	remove	(const char *) ;
 int	rename	(const char *, const char *) ;
 char *	tmpnam	(char *) ;
 FILE *	tmpfile	(void) ;

 int	fclose	(FILE *) ;
 int	fflush	(FILE *) ;

 FILE *	fopen	(const char *, const char *) ;
 FILE *	freopen	(const char *, const char *, FILE *) ;

 void	setbuf	(FILE *, char *) ;
 int	setvbuf	(FILE *, char *, int, size_t) ;
# 132 "C:/c68/include/stdio.h"
 int  fscanf  (FILE *, const char *, ...) ;
 int  scanf   (const char *, ...) ;
 int  sscanf  (const char *, const char *, ...) ;


 int	fprintf	(FILE *, const char *, ...) ;
 int	printf	(const char *, ...) ;
 int	sprintf	(char *, const char *, ...) ;

 int 	vfprintf (FILE *, const char *, char * ) ;
 int 	vprintf	 (const char *, char * ) ;
 int 	vsprintf (char *, const char *, char * ) ;

 int	vscanf  (const char *, char * ) ;
 int	vfscanf (FILE *, const char *, char * ) ;
 int	vsscanf	(const char *, const char *, char * ) ;


 int	fgetc	(FILE *) ;
 char	*fgets	(char *, int, FILE *) ;
 char	*gets	(char *) ;
 int	fputc	(int c, FILE *) ;
 int	fputs	(const char *, FILE *) ;
 int	puts	(const char *) ;

 size_t	fread	(void *, size_t, size_t, FILE *) ;
 size_t	fwrite	(const void *, size_t, size_t, FILE *) ;

 int	fgetpos	(FILE *, fpos_t *) ;
 int	fsetpos	(FILE *, fpos_t *) ;

 int	fseek	(FILE *, long, int) ;
 long	ftell	(FILE *) ;
 void	rewind	(FILE *) ;

 void	perror	(const char *) ;


 FILE	*fdopen	(int, const char *) ;


 FILE *	fopenp	(const char *, const char *) ;
 int 	fungetc	(int, FILE *) ;
 int	pclose	(FILE *) ;
 FILE *	popen	(const char *, const char *) ;
 void	setlinebuf	(FILE *) ;

 void	_binmode	(int) ;
 long 	getl	(FILE *) ;
 long 	putl	(long, FILE *) ;
 short 	getw	(FILE *) ;
 short 	putw	(short, FILE *) ;
 void	_getbuf	(FILE *fp) ;
# 192 "C:/c68/include/stdio.h"
 int	_filbuf	(FILE *) ;
# 4 "./GAME.H" 2
# 1 "./types.h" 1



typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;
# 5 "./GAME.H" 2
# 1 "./render.h" 1
# 1 "C:/c68/include/stdio.h" 1
# 4 "./render.h" 2
# 1 "C:/c68/include/osbind.h" 1
# 5 "./render.h" 2
# 1 "./TYPES.H" 1
# 6 "./render.h" 2
# 1 "./RASTER.H" 1
# 1 "./types.h" 1
# 17 "./RASTER.H" 2
# 1 "./font.h" 1
# 1 "./types.h" 1
# 4 "./font.h" 2


extern const UINT8 font[];
# 18 "./RASTER.H" 2
# 33 "./RASTER.H"
void clearScreen(UINT32 *base);
# 46 "./RASTER.H"
void plot_Vertical_Line(UINT8 *base, int x, int y1, int y2);
# 59 "./RASTER.H"
void plot_Horizontal_Line(UINT8 *base, int x1, int x2, int y);
# 72 "./RASTER.H"
void plot_Square(UINT16 *base, int x1 ,int x2, int y1, int y2);
# 85 "./RASTER.H"
void plot_glyph(UINT8 *base, char thisChar, int x, int y);
# 98 "./RASTER.H"
void plot_Background(UINT32 *base, const UINT32 *bitmap, int x, int y,int bitmap_height);
# 111 "./RASTER.H"
void plot_bitmap8(UINT8 *base, const UINT8 *bitmap, int x, int y,int bitmap_height);
# 124 "./RASTER.H"
void plot_bitmap16(UINT16 *base, const UINT16 *bitmap, int x, int y,int bitmap_height);
# 137 "./RASTER.H"
void clear16X16(UINT16 *base, const UINT16 *bitmap, int x, int y,int bitmap_height);
# 150 "./RASTER.H"
void plot_bitmap32(UINT32 *base, const UINT32 *bitmap, int x, int y,int bitmap_height);
# 163 "./RASTER.H"
void clear32X32(UINT32 *base, const UINT32 *bitmap, int x, int y,int bitmap_height);
# 7 "./render.h" 2
# 1 "./MODEL.H" 1
# 1 "C:/c68/include/stdio.h" 1
# 17 "./MODEL.H" 2





typedef int bool;
# 42 "./MODEL.H"
struct BoundingBox{

	unsigned int height;
	unsigned int length;
	unsigned int hotSpotX;
	unsigned int hotSpotY;
};
# 61 "./MODEL.H"
struct SawBlade{
	struct BoundingBox bBox;

	unsigned int speed, initialX, initialY, x, y;
	bool forward;
	int timer;

};
# 81 "./MODEL.H"
struct Hero{
	struct BoundingBox bBox;
	signed int deltaX, deltaY;
	unsigned int speed, health, initialX, initialY, spriteHeight;
	bool isJumping, isFacingForwards, isInvincible, isFalling;
};
# 99 "./MODEL.H"
struct Platform{

	struct BoundingBox bBox;

	unsigned int x, y;
};
# 117 "./MODEL.H"
struct Screen{
	struct BoundingBox bBox;
	bool isPlayerDead;
	struct Hero hero;
	struct SawBlade sawBlades[2 ];
	struct Platform platForms[6 ];
	unsigned int entranceX, entranceY, exitX, exitY;
	signed int jumpCounter;
};
# 138 "./MODEL.H"
struct Model{
	struct Screen levelScreens[4];
	unsigned int time;
	int currentScreen;
	signed int direction;
 	signed int jumpCounter;
	int invincCounter;
	bool gameOver;
	bool gameWon;
	bool endReached;
};
# 162 "./MODEL.H"
struct ModelSaves{
	int heroX,
		heroY;
	int	sawBladeX[2 ];
	int sawBladeY[2 ];

};
# 181 "./MODEL.H"
void move_Hero(struct Hero *hero, int direction);
void hero_Hit(struct Hero *hero);
void hero_Jump(struct Hero *hero);
void hero_Fall(struct Hero *hero);
# 198 "./MODEL.H"
void move_SawBlade(struct SawBlade *sawBlade, struct Platform *platform);
void check_SawBlade_Collision(struct Hero *hero, struct SawBlade *sawBlade);
void check_Platform_Collision(struct Hero *hero, struct Platform *platform);
void move_Screen(struct Hero *hero,const struct Model *model);
# 215 "./MODEL.H"
void incrementJumpCounter(struct Model *model);
# 229 "./MODEL.H"
void set_Hero_Direction(struct Model *model, int direction);
# 243 "./MODEL.H"
void move_Screen(struct Hero *hero,struct Model *model);
# 8 "./render.h" 2
# 1 "./BITMAPS.H" 1



extern const unsigned int CLEAR_16X16 [];

extern const unsigned int LEFT_HERO_1 [];

extern const unsigned int LEFT_HERO_2 [];

extern const unsigned int RIGHT_HERO_1 [];

extern const unsigned int RIGHT_HERO_2 [];

extern const unsigned int LEFT_HERO_JUMP [];

extern const unsigned int LEFT_HERO_FALL [];

extern const unsigned int RIGHT_HERO_JUMP [];

extern const unsigned int RIGHT_HERO_FALL [];

extern const unsigned long CLEAR_32X32 [];

extern const unsigned long SAWBLADE [];

extern const unsigned long HEARTS_3 [];

extern const unsigned long HEARTS_2 [];

extern const unsigned long HEARTS_1 [];

extern const unsigned char PLATFORM_NORMAL [];

extern const unsigned char LEFT_PLATFORM_EDGE [];

extern const unsigned char RIGHT_PLATFORM_EDGE [];

extern const unsigned int SELECTION_ARROW [];

extern const unsigned int EXITDOOR [];
# 9 "./render.h" 2
# 1 "./back1.h" 1



extern const unsigned long BACKGROUND_LEVEL_1 [];

extern const unsigned long BACKGROUND_LEVEL_2 [];
# 10 "./render.h" 2
# 1 "./back2.h" 1



extern const unsigned long BACKGROUND_LEVEL_3 [];

extern const unsigned long BACKGROUND_LEVEL_4 [];
# 11 "./render.h" 2
# 1 "./ONESS.H" 1



extern const unsigned long LOSE_SCREEN [];

extern const unsigned long START_SCREEN [];
# 12 "./render.h" 2
# 1 "./TWOSS.H" 1



extern const unsigned long WINNER_SCREEN [];
# 13 "./render.h" 2
# 22 "./render.h"
void render(const struct Model *model, UINT32 *base);

void render_Platform(const struct Platform *platform, UINT32 *base);

void render_Hero(const struct Hero *hero, UINT16* base);

void render_SawBlade(const struct SawBlade *sawBlade, UINT32 *base);

void render_Health(const struct Hero *hero, UINT32 *base);

void render_Updates(const struct Model *model, UINT32 *base);

void render_ClearHero(UINT16 *base, int heroX, int heroY);

void render_ClearSawblade(UINT32 *base, int sawBladeX, int sawBladeY);

void render_ClearHeart(UINT32 *base);

void erase(UINT32 *base, const struct Model *model, const struct ModelSaves* backSave);

void render_GameOver(UINT32 *base);

void render_Menu(UINT32 *base);

void render_Background(const struct Model *model,UINT32 *base);

void render_ArrowPositionOne(UINT32 *base);

void render_ArrowPositionTwo(UINT32 *base);
# 6 "./GAME.H" 2
# 1 "./model.h" 1
# 7 "./GAME.H" 2
# 1 "./events.h" 1
# 1 "C:/c68/include/stdio.h" 1
# 5 "./events.h" 2
# 1 "./MODEL.H" 1
# 6 "./events.h" 2
# 1 "./effects.h" 1
# 1 "./psg.h" 1
# 1 "C:/c68/include/osbind.h" 1
# 1 "./psg.h" 2
# 1 "./types.h" 1
# 2 "./psg.h" 2


void write_psg(int reg, UINT8 val);
UINT8 read_psg(int reg);
void set_tone(int channel, int tuning);
void set_volume(int channel, int volume);
void enable_channel(int channel, int tone_on, int noise_on);
void stop_sound();
void set_noise(int tuning);
void set_envelope(int shape, unsigned int sustain);
# 1 "./effects.h" 2


void play_nextLevel();
void play_gunshot();
void ding();
# 7 "./events.h" 2
# 1 "./psg.h" 1
# 1 "C:/c68/include/osbind.h" 1
# 1 "./psg.h" 2
# 1 "./types.h" 1
# 2 "./psg.h" 2


void write_psg(int reg, UINT8 val);
UINT8 read_psg(int reg);
void set_tone(int channel, int tuning);
void set_volume(int channel, int volume);
void enable_channel(int channel, int tone_on, int noise_on);
void stop_sound();
void set_noise(int tuning);
void set_envelope(int shape, unsigned int sustain);
# 8 "./events.h" 2
# 20 "./events.h"
void event_UpdateWorld(struct Model *model);


void event_Left(struct Model *model);


void event_Right(struct Model *model);


void event_Jump(struct Model *model);
# 8 "./GAME.H" 2
# 1 "./psg.h" 1
# 1 "C:/c68/include/osbind.h" 1
# 1 "./psg.h" 2
# 1 "./types.h" 1
# 2 "./psg.h" 2


void write_psg(int reg, UINT8 val);
UINT8 read_psg(int reg);
void set_tone(int channel, int tuning);
void set_volume(int channel, int volume);
void enable_channel(int channel, int tone_on, int noise_on);
void stop_sound();
void set_noise(int tuning);
void set_envelope(int shape, unsigned int sustain);
# 9 "./GAME.H" 2
# 1 "./music.h" 1
# 1 "./types.h" 1
# 4 "./music.h" 2
# 1 "./psg.h" 1
# 1 "C:/c68/include/osbind.h" 1
# 1 "./psg.h" 2
# 1 "./types.h" 1
# 2 "./psg.h" 2


void write_psg(int reg, UINT8 val);
UINT8 read_psg(int reg);
void set_tone(int channel, int tuning);
void set_volume(int channel, int volume);
void enable_channel(int channel, int tone_on, int noise_on);
void stop_sound();
void set_noise(int tuning);
void set_envelope(int shape, unsigned int sustain);
# 5 "./music.h" 2
# 32 "./music.h"
typedef struct Note
{
	UINT8 key;
	int duration;
	int volume;

} note;

void start_music();
void update_music();
# 10 "./GAME.H" 2
# 24 "./GAME.H"
UINT32 get_time();
# 37 "./GAME.H"
void flip_Screen(long *front, long *back);
# 50 "./GAME.H"
void saveLocation(const struct Model* model, struct ModelSaves *modelSave);
# 63 "./GAME.H"
void menu(UINT32 *base);
# 76 "./GAME.H"
void end_Result(UINT32 *base,struct Model *model);
# 90 "./GAME.H"
void render_GameWon(UINT32 *base);
# 4 "game.c" 2




long *timer = (long *)0x462;
UINT8 buffer[32256];
UINT8 background[32256];


int main(){

	long *frontScreen;
	long *backScreen;
	long *backgroundSave;

	struct Model model = {
	{
		{
		{400,640,0,0},
		0 ,
		{
		{16, 16, 6, 0},
		6,0,1,3,6,0,16,
		0 ,
		-1 ,
		0 ,
		-1 
		},
		{
		{
		{32, 32, 200, 50},
		1, 200, 50, 200, 50,
		0 ,
		0
		}
		,
		{
		{32, 32, 424, 200},
		1, 424, 200, 426, 200,
		0 ,
		2
		}
		,
		},
		{
		{{16, 64, 0, 20},
		0,51},
		{{16, 64, 100, 90},
		100,121},
		{{16, 64, 200, 50},
		200,81},
		{{16, 64, 350, 25},
		350,56},
		{{16, 64, 424, 200},
		424,231},
		{{16, 64, 576, 169},
		576,200}
		},
		6,0,
		624,200,
		20
		},
		{
		{400,640,0,0},
		0 ,
		{
		{16, 16, 6, 50},
		6,50,1,3,6,50,16,
		0 ,
		-1 ,
		0 ,
		-1 
		},
		{
		{
		{32, 32, 226, 20},
		1, 226, 20, 226, 20,
		0 ,
		0
		}
		,
		{
		{32, 32, 428, 50},
		1, 428, 50, 428, 50,
		0 ,
		2
		}
		,
		},
		{
		{{16, 64, 0, 169},
		0,200},
		{{16, 64, 164, 130},
		164,161},
		{{16, 64, 226, 20},
		226,51},
		{{16, 64, 328, 89},
		328,120},
		{{16, 64, 428, 50},
		428,81},
		{{16, 64, 576, 25},
		576,56}
		},
		6,50,
		624,56,
		30
		},
		{
		{400,640,0,0},
		0 ,
		{
		{16, 16, 6, 120},
		6,120,1,3,6,120,16,
		0 ,
		-1 ,
		0 ,
		-1 
		},
		{
		{
		{32, 32, 226, 20},
		1, 226, 20, 226, 20,
		0 ,
		0
		}
		,
		{
		{32, 32, 430, 160},
		1, 430, 160, 430, 160,
		0 ,
		2
		}
		,
		},
		{
		{{16, 64, 0, 169},
		0,200},
		{{16, 64, 164, 130},
		164,161},
		{{16, 64, 226, 20},
		226,51},
		{{16, 64, 328, 89},
		328,120},
		{{16, 64, 430, 160},
		430,191},
		{{16, 64, 576, 133},
		576,164}
		},
		6,50,
		624,164,
		27
		},
		{
		{400,640,0,0},
		0 ,
		{
		{16, 16, 6, 180},
		6,180,1,3,6,180,16,
		0 ,
		-1 ,
		0 ,
		-1 
		},
		{
		{
		{32, 32, 226, 20},
		1, 226, 20, 226, 20,
		0 ,
		0
		}
		,
		{
		{32, 32, 430, 160},
		1, 430, 160, 430, 160,
		0 ,
		2
		}
		,
		},
		{
		{{16, 64, 0, 169},
		0,200},
		{{16, 64, 126, 169},
		126,200},
		{{16, 64, 220, 169},
		226,200},
		{{16, 64, 330, 169},
		330,200},
		{{16, 64, 450, 146},
		450,177},
		{{16, 64, 576, 133},
		576,164}
		},
		6,50,
		624,164,
		15
		},
	},
	0,
	0,
	0,
	0,
	0,
	0 ,
	0 ,
	0 
	};

	struct ModelSaves frontSave = {
		6,
		0,
		{
		202,
		426
		},
		{
		50,
		200
		},
	};

	struct ModelSaves backSave = {
		6,
		0,
		{
		202,
		426,
		},
		{
		50,
		200,
		},
	};


	long in;
	long * temp;
	UINT32 timeThen = 0L, timeNow = 0L, timeElapsed = 0L;

	frontScreen = (void*)_trap_14_w((short)0x2) ;

	temp = frontScreen;

	backScreen = (long []) buffer;
	backScreen = (long *)((long)(backScreen + 256) & 0xffffff00L);

	backgroundSave = (long [])background;
	backgroundSave = (long *)((long)(backgroundSave + 256) & 0xffffff00L);


	menu((UINT32 *) frontScreen);

	if(model.endReached == 0 ){
		render_Background(&model,(UINT32 *)backgroundSave);
	}


	render(&model, (UINT32 *) frontScreen);
	render(&model, (UINT32 *) backScreen);

	timeThen = get_time();
	start_music();

	while (model.gameOver == 0 )
	{

		if((short)_trap_1_w((short)0x0B) ){
			in = _trap_1_w((short)0x08) ;

			switch (in)
			{
			case 0x004B0000L :

				event_Left(&model);

				break;
			case 0x004D0000L :

				event_Right(&model);

				break;

			case 0x00390020L :

				event_Jump(&model);

				break;

			case 0x001C000DL :
				model.gameOver = -1 ;
				stop_sound();
				break;

			default:
				break;
			}
		}

		timeNow = get_time();
		timeElapsed = timeNow - timeThen;

		if(timeElapsed > 0){

			erase((UINT32 *) backScreen, &model, &backSave);

			saveLocation(&model,&frontSave);

			event_UpdateWorld(&model);

			if(model.endReached == -1 ){
				render_Background(&model,(UINT32 *)backgroundSave);
				model.endReached = 0 ;
			}
			update_music();
			memcpy(backScreen,backgroundSave,32256);

			render_Updates(&model,(UINT32 *) backScreen);

			saveLocation(&model,&backSave);

			flip_Screen((long *)&frontScreen,(long *)&backScreen);

			erase((UINT32 *) backScreen, &model, &frontSave);

			timeThen = timeNow;
			(void)_trap_14_w((short)0x25) ;
		}


	}



	if (temp != frontScreen)
	{
		flip_Screen((long *)&frontScreen,(long *)&backScreen);
	}
	(void)_trap_14_w((short)0x25) ;

	end_Result((UINT32 *) frontScreen,&model);

	return 0;
}


void flip_Screen(long *front, long *back)
{
	long *tmp;
	tmp = (long *)*front;
	*front = *back;
	*back = (long *)tmp;

	(void)_trap_14_wllw((short)0x5,(long)(-1L),(long)*front,(short)(-1L)) ;

}


UINT32 get_time(){
	long timeNow;
	long old_ssp;

	old_ssp = _trap_1_wl((short)0x20,(long)(0)) ;
	timeNow = *timer;
	_trap_1_wl((short)0x20,(long)(old_ssp)) ;

	return timeNow;
}

void saveLocation(const struct Model* model, struct ModelSaves *modelSave){

	modelSave->heroX = model->levelScreens[0].hero.deltaX;
	modelSave->heroY = model->levelScreens[0].hero.deltaY;
	modelSave->sawBladeX[0] = model->levelScreens[model->currentScreen].sawBlades[0].x;
	modelSave->sawBladeY[0] = model->levelScreens[model->currentScreen].sawBlades[0].y;
	modelSave->sawBladeX[1] = model->levelScreens[model->currentScreen].sawBlades[1].x;
	modelSave->sawBladeY[1] = model->levelScreens[model->currentScreen].sawBlades[1].y;
}

void menu(UINT32 *base){

	bool selection = 0 ;
	long in;

	render_Menu((UINT32 *)base);
	(void)_trap_14_wllw((short)0x5,(long)(-1L),(long)base,(short)(-1L)) ;
	(void)_trap_14_w((short)0x25) ;

	while(selection == 0 ){
		if((short)_trap_1_w((short)0x0B) ){
				in = _trap_1_w((short)0x08) ;

				switch (in)
				{
				case 0x00480000L :

					render_ArrowPositionOne((UINT32 *)base);
					break;

				case 0x00500000L :
					render_ArrowPositionTwo((UINT32 *)base);
					break;

				case 0x001C000DL :
					selection = -1 ;
					break;

			default:
				break;
			}
		}
		(void)_trap_14_w((short)0x25) ;
	}

}

void end_Result(UINT32 *base, const struct Model *model){

	if(model->gameWon == -1 ){
		render_GameWon((UINT32 *) base);
	}
	else{

		render_GameOver((UINT32 *) base);

	}
	(void)_trap_14_w((short)0x25) ;
}
