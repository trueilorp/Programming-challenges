import sys

def solve(n, out_nei):
	# Implementazione della funzione solve (un esempio placeholder)
	dist = [0] * n
	dad = [-1] * n
	num_BFStrees = 1  # Placeholder value

	# Questa è solo una funzione di esempio.
	# La logica reale dovrebbe essere implementata qui.
	return dist, dad, num_BFStrees

if __name__ == "__main__":
	import sys
	argv = sys.argv
	debug_level = 0
	if len(argv) == 2:
		debug_level = int(argv[1])

	T = int(input())
	for t in range(1, 1 + T):
		if debug_level > 0:
			print(f"#\n# Testcase {t}:", file=sys.stderr)
		n, m = map(int, input().strip().split())
		out_nei = [[] for _ in range(n)]
		for _ in range(m):
			a, b = map(int, input().strip().split())
			out_nei[a].append(b)
		if debug_level > 1:
			print(f"# {n=}, {m=}, {out_nei=}", file=sys.stderr)
		dist, dad, num_BFStrees = solve(n, out_nei)
		if debug_level > 2:
			print(f"# {dist=}\n# {dad=}\n# {num_BFStrees=}", flush=True, file=sys.stderr)
		# Stampa i risultati (decommenta queste righe se vuoi vedere i risultati)
		# print(" ".join(map(str, dist)))
		# print(" ".join(map(str, dad)))
		# print(num_BFStrees)
