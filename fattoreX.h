/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _FATTOREX_H_RPCGEN
#define _FATTOREX_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define MAXCANDIDATI 15
#define MAXGIUDICI 5

struct Candidato {
	char candidato[32];
	char giudice[32];
	char categoria;
	char nomeFile[32];
	char fase;
	int voto;
};
typedef struct Candidato Candidato;

struct Candidati {
	Candidato candidato[MAXCANDIDATI];
};
typedef struct Candidati Candidati;

struct Giudice {
	char nomeGiudice[32];
	int punteggio;
};
typedef struct Giudice Giudice;

struct Output {
	Giudice giudici[MAXGIUDICI];
};
typedef struct Output Output;

struct Input {
	char candidato[32];
	char operazione[16];
};
typedef struct Input Input;

#define FATTOREXPROG 0x20000013
#define FATTOREXVERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define CLASSIFICA_GIUDICI 1
extern  Output * classifica_giudici_1(void *, CLIENT *);
extern  Output * classifica_giudici_1_svc(void *, struct svc_req *);
#define ESPRIMI_VOTO 2
extern  int * esprimi_voto_1(Input *, CLIENT *);
extern  int * esprimi_voto_1_svc(Input *, struct svc_req *);
extern int fattorexprog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define CLASSIFICA_GIUDICI 1
extern  Output * classifica_giudici_1();
extern  Output * classifica_giudici_1_svc();
#define ESPRIMI_VOTO 2
extern  int * esprimi_voto_1();
extern  int * esprimi_voto_1_svc();
extern int fattorexprog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_Candidato (XDR *, Candidato*);
extern  bool_t xdr_Candidati (XDR *, Candidati*);
extern  bool_t xdr_Giudice (XDR *, Giudice*);
extern  bool_t xdr_Output (XDR *, Output*);
extern  bool_t xdr_Input (XDR *, Input*);

#else /* K&R C */
extern bool_t xdr_Candidato ();
extern bool_t xdr_Candidati ();
extern bool_t xdr_Giudice ();
extern bool_t xdr_Output ();
extern bool_t xdr_Input ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_FATTOREX_H_RPCGEN */
