import subprocess
import threading


subprocess.check_call("g++ -std=c++11 ../bipartite-graph.cpp", shell=True)

proc = sb.Popen("../a.out", shell=True, stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                stderr=subprocess.PIPE)

out, err = proc.communicate('hello\n')

assert proc.returncode == 0
assert out == 'hello\n'
assert err == ''
sb.check_call("main", shell=True)
