package MODUL4;

import java.util.Arrays;

public class krukal {
    class Edge implements Comparable<Edge> {
        int src, dest, weight;

        public int compareTo(Edge compareEdge) {
            return this.weight - compareEdge.weight;
        }
    }
    /*
     * pendeklarasikan class edge yang
     * merepresentsaikan bagian tepi. Menggunakan pembanding untuk menyortir
     * tepi berdasarkan beratnya.
     */

    class subset {
        int parent, rank;
    }
    /*
     * class subset yang digunaan
     * untuk mendeklarasikan variabel parent dan rank yang bertipe data int(integer)
     * yang akan membaca data berupa angka.
     */

    int vertices, edges;
    Edge edge[];

    krukal(int v, int e) {
        vertices = v;
        edges = e;
        edge = new Edge[edges];
        for (int i = 0; i < e; ++i)
            edge[i] = new Edge();
    }
    /*
     * mendeklasikan variabel vertices dan
     * edges yang bertipe data int (integer) yang akan membaca data berupa angka.
     * Edge edge[ ]; akan menyimpan semua sisi. Mulai dari krukal (int vertices,
     * int edges){ sampai dengan } akan membuat graph dengan simpul vertices
     * simpul dan sisi edges.
     */

    int find(subset subsets[], int i) {
        if (subsets[i].parent != i)
            subsets[i].parent = find(subsets, subsets[i].parent);
        return subsets[i].parent;
    }
    /*
     * fungsi utilitas untuk
     * menemukan kumpulan elemen i (menggunakan teknik kompresi jalur).
     * Menemukan root dan menjadikan root sebagai induk dari i (kompresi jalur).
     */

    void Union(subset subsets[], int x, int y) {
        int xroot = find(subsets, x);
        int yroot = find(subsets, y);
        if (subsets[xroot].rank < subsets[yroot].rank)
            subsets[xroot].parent = yroot;
        else if (subsets[xroot].rank > subsets[yroot].rank)
            subsets[yroot].parent = xroot;
        else {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }
    /*
     * void Union yang memiliki
     * fungsi menggabungkan dua set dari x dan y (menggunakan gabungan
     * berdasarkan peringkat.
     */
    void KruskalAlgo() {
        Edge result[] = new Edge[vertices];
        int e = 0;
        int i = 0;
        for (i = 0; i < vertices; ++i)
            result[i] = new Edge();
        Arrays.sort(edge);
        subset subsets[] = new subset[vertices];
        for (i = 0; i < vertices; ++i)
            subsets[i] = new subset();
        for (int v = 0; v < vertices; ++v) {
            subsets[v].parent = v;
            subsets[v].rank = 0;
        }
        i = 0;
        while (e < vertices - 1) {
            Edge next_edge = new Edge();
            next_edge = edge[i++];
            int x = find(subsets, next_edge.src);
            int y = find(subsets, next_edge.dest);
            if (x != y) {
                result[e++] = next_edge;
                Union(subsets, x, y);
            }
        }
        for (i = 0; i < e; ++i)
            System.out.println(result[i].src + " - " + result[i].dest + ": " +
                    result[i].weight);
    }

    /*
     * Potongan program di bawah ini merupakan fungsi utama membangun
     * minimum spanning tree menggunakan algoritma kruskal.
     * Langkah-langkah dalam fungsi utama:
     * 1) Urutkan semua tepi dalam nonpenurunan urutan beratnya. Jika kita tidak
     * diijinkan ubah graph yang diberikan, kita dapat membuat salinannya
     * susunan tepi.
     * 2) Pilih tepi terkecil dan kenaikan indeks untuk iterasi berikutnya.
     * Hasil yang di dapatkan akan di tampilkan dengan perintah System.out.println
     */
    public static void main(String[] args) {
        int vertices = 7; // Number of vertices
        int edges = 14; // Number of edges
        krukal G = new krukal(vertices, edges);

        G.edge[0].src = 0;
        G.edge[0].dest = 6;
        G.edge[0].weight = 15;

        G.edge[1].src = 3;
        G.edge[1].dest = 4;
        G.edge[1].weight = 2;

        G.edge[2].src = 2;
        G.edge[2].dest = 6;
        G.edge[2].weight = 10;

        G.edge[3].src = 1;
        G.edge[3].dest = 2;
        G.edge[3].weight = 4;

        G.edge[4].src = 2;
        G.edge[4].dest = 4;
        G.edge[4].weight = 5;

        G.edge[5].src = 3;
        G.edge[5].dest = 5;
        G.edge[5].weight = 7;

        G.edge[6].src = 1;
        G.edge[6].dest = 4;
        G.edge[6].weight = 3;

        G.edge[7].src = 0;
        G.edge[7].dest = 2;
        G.edge[7].weight = 12;

        G.edge[8].src = 1;
        G.edge[8].dest = 5;
        G.edge[8].weight = 8;

        G.edge[9].src = 1;
        G.edge[9].dest = 3;
        G.edge[9].weight = 2;

        G.edge[10].src = 4;
        G.edge[10].dest = 5;
        G.edge[10].weight = 6;

        G.edge[11].src = 0;
        G.edge[11].dest = 4;
        G.edge[11].weight = 11;

        G.edge[12].src = 4;
        G.edge[12].dest = 6;
        G.edge[12].weight = 14;
        G.edge[13].src = 0;
        G.edge[13].dest = 1;
        G.edge[13].weight = 9;
        G.KruskalAlgo();

    }
}

/*
 * data-data dari jalur terpendek
 * yang akan di buat. Src adalah simpul awal atau titik awal, dest adalah simpul
 * awal atau titik tujuan, dan yang terakhir ada weight yang berarti panjang
 * jarak
 * antar titik awal ke titik tujuan.
 */